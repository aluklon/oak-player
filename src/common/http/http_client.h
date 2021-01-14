#pragma once

// Local headers
#include "request.h"

namespace oak {
namespace http {

class HttpClient {
public:
    void get(const Request& request);
};

} // namespace http
} // namespace oak
