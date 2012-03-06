/*
 * Central loop and control for Darwin
 * Andrew Melim
 * Requires: libtcod-1.5.1
 */

#include "libtcod.hpp"
#include <stdio.h>


void init() {}
void render() {}
void update() {}

int main(int argc, char** argv)
{
    TCODConsole::initRoot(40,40, "Darwin", false, TCOD_RENDERER_SDL);
    TCODConsole::root->setAlignment(TCOD_CENTER);
    TCOD_key_t k = {TCODK_NONE,0};
    TCOD_mouse_t mouse;
    init();

    while(!TCODConsole::isWindowClosed())
    {
        render();
        TCODConsole::flush();
        TCODSystem::checkForEvent((TCOD_event_t)TCOD_EVENT_KEY_PRESS,
                                  &k,&mouse);
    }
    return 0;
}
