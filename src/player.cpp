#include "player.h"

// C++ headers
#include <thread>

// Local headers
#include "common/event_loop.h"
#include "common/http/http_client.h"

namespace oak {

static void ThreadFunc(EventLoop* loop) {
    loop->run();
}

class Player::Impl {
public:
    Impl();

    void load(const std::string& url);

    EventLoop _loop;
    std::thread _thread;

    http::HttpClient _httpClient;
};

Player::Impl::Impl()
    : _thread(ThreadFunc, &_loop) {
}

void Player::Impl::load(const std::string &url) {
    _loop.dispatch([this, url] () {
        _httpClient.get(http::Request(url));
    });
}

Player::Player()
    : _impl(new Impl()) {
}

Player::~Player() {
    delete _impl;
}

void Player::load(const std::string& url) {
    _impl->load(url);
}

} // namespace oak
