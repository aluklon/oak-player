#pragma once

// C++ headers
#include <functional>

namespace oak {
namespace common {

class EventLoop {
public:
    class Impl;
    using Func = std::function<void()>;

    EventLoop();
    ~EventLoop();

    void run();
    void dispatch(Func&& func);

private:
    Impl* _impl {nullptr};
};

} // namespace common
} // namespace oak
