/*
 * Central loop and control for Darwin
 * Andrew Melim
 * Requires: libtcod-1.5.1
 */

#include "libtcod.hpp"
#include "rad_shader.hpp"
#include "player.h"
#include <stdio.h>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 50 

#define LIGHT_RADIUS 8 
#define CELL_REFLECTIVITY 1.5
#define CELL_SELF_ILLUMINATION 0.4

TCODMap *map;
Player *player;
Shader *shader;

int gamma[256];

void init() 
{
    player = new Player();
    map = new TCODMap(SCREEN_WIDTH,SCREEN_HEIGHT);
    shader = new PhotonShader(CELL_REFLECTIVITY, CELL_SELF_ILLUMINATION, 10);
    shader->addLight(player->getX(), player->getY(), LIGHT_RADIUS, TCODColor::lightAzure);
    shader->addLight(player->getX() + 2, player->getY(), LIGHT_RADIUS, TCODColor::red);
    shader->init(map);

    for(int i=0; i<256; i++)
            gamma[i] = i;
}
void render() 
{
    shader->compute();

    for(int i = 0; i < SCREEN_WIDTH; i++)
        for(int j = 0; j <SCREEN_HEIGHT; j++)
        {
            TCODColor light = shader->getLightColor(i,j) * TCODColor::darkAzure;
            //TCODColor cellCol = TCODColor::lerp(TCODColor::black,light, gamma[light.r]/255.0f);
            TCODConsole::root->setCharBackground(i,j,light);
        }

    //Draw player
    TCODConsole::root->setCharForeground(player->getX(),player->getY(),player->getColor());
    TCODConsole::root->setChar(player->getX(),player->getY(),player->getChar());
}
void update() {}

int main(int argc, char** argv)
{
    TCODConsole::initRoot(SCREEN_WIDTH, SCREEN_HEIGHT, "Darwin", false, TCOD_RENDERER_SDL);
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
