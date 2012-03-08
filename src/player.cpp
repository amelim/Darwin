#include "player.h"

Player::Player()
{
    x = 20;
    y = 20;
    color = TCODColor::white;
    ch = '@';
}

Player::Player(int i, int j, TCODColor c, char chr)
{
    x = i;
    y = j;
    color = c;
    ch = chr;
}

void Player::move(int dx, int dy)
{
    x = x + dx;
    y = y + dy;
}
