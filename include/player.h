#include "libtcod.hpp"

class Player
{

    private:
        int x,y;
        TCODColor color;
    public:
        Player();
        Player(int i, int j, TCODColor c);

        //Helper functions
        int getX() {return x;}
        int getY() {return y;}

        //State functions
        void render();
        void update();

};
