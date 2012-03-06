#include "player.h"

Player::Player()
{
    x = 0;
    y = 0;
    color = TCODColor::white;
}

Player::Player(int i, int j, TCODColor c)
{
    x = i;
    y = j;
    color = c;
}
