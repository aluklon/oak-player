#pragma once

// C++ headers
#include <string>

namespace oak {
namespace http {

class Request {
public:
    Request() {}
    explicit Request(const std::string& url)
        : _url(url)
    {}

private:
    std::string _url;
};

} // namespace http
} // namespace oak
