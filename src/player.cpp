#include "player.h"

// Local headers
#include "common/http/http_client.h"

namespace oak {

class Player::Impl {
public:
    void load(const std::string& url);

    http::HttpClient _httpClient;
};

void Player::Impl::load(const std::string &url) {
    _httpClient.get(http::Request(url));
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
