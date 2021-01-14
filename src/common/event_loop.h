#pragma once

// C++ headers
#include <functional>

namespace oak {

class EventLoop {
public:
    class Impl;
    using Func = std::function<void()>;

    EventLoop();
    ~EventLoop();

    void run();
    void dispatch(Func&& func);

private:
    Impl* const _impl {nullptr};
};

} // namespace oak
