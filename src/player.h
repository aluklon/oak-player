#pragma once

// C++ headers
#include <string>

namespace oak {

class Player {
public:
    Player();
    ~Player();

    void load(const std::string& url);

private:
    class Impl;
    Impl* const _impl {nullptr};
};

} // namespace oak
