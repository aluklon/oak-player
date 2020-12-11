#include "event_loop.h"

// C++ headers
#include <mutex>
#include <queue>

// Libev headers
#include <ev.h>

namespace oak {
namespace common {

class EventLoop::Impl {
public:
    Impl();
    ~Impl();

    void run();
    void dispatch(EventLoop::Func&& func);

    void execFunctions();

    ev_async _asyncWatcher;
    struct ev_loop* _evLoop {nullptr};

    std::mutex _mutex;
    std::queue<EventLoop::Func> _queue;
};

static void Callback(struct ev_loop*, ev_async* w, int) {
    static_cast<EventLoop::Impl*>(w->data)->execFunctions();
}

EventLoop::Impl::Impl() {
    _evLoop = ev_loop_new();
    _asyncWatcher.data = this;
    ev_async_init(&_asyncWatcher, Callback);
    ev_async_start(_evLoop, &_asyncWatcher);
}

EventLoop::Impl::~Impl() {
    ev_async_stop(_evLoop, &_asyncWatcher);
    ev_loop_destroy(_evLoop);
}

void EventLoop::Impl::run() {
    ev_run(_evLoop, 0);
}

void EventLoop::Impl::dispatch(Func&& func) {
    _mutex.lock();
    _queue.push(std::move(func));
    _mutex.unlock();

    ev_async_send(_evLoop, &_asyncWatcher);
}

void EventLoop::Impl::execFunctions() {
    while (true) {
        EventLoop::Func func;
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_queue.empty()) {
                break;
            }
            func = _queue.front();
            _queue.pop();
        }
        func();
    }
}

EventLoop::EventLoop()
    : _impl(new Impl()) {
}

EventLoop::~EventLoop() {
    delete _impl;
}

void EventLoop::run() {
    _impl->run();
}

void EventLoop::dispatch(Func&& func) {
    _impl->dispatch(std::move(func));
}

} // namespace common
} // namespace oak
