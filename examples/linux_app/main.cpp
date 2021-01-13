// Oakplayer headers
#include "player.h"
#include "common/event_loop.h"

int main() {
    oak::EventLoop mainLoop;

    oak::Player player;
    player.load("https://dash.akamaized.net/akamai/bbb_30fps/bbb_30fps.mpd");

    mainLoop.run();
    return 0;
}
