#include "player.h"

// C++ headers
#include <thread>

// Local headers
#include "common/event_loop.h"
#include "common/http/http_client.h"

namespace oak {

class Player::Impl {
public:
    Impl();
    ~Impl();

    void load(const std::string& url);

    EventLoop* _loop = nullptr;
    std::thread _thread;

    http::HttpClient _httpClient;
};

Player::Impl::Impl()
    : _loop(new EventLoop())
    , _thread(&EventLoop::run, std::ref(_loop)) {
}

Player::Impl::~Impl() {
    _loop->dispatch([this] () {
        delete _loop;
    });
    _thread.join();
}

void Player::Impl::load(const std::string &url) {
    _loop->dispatch([this, url] () {
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
