#include "RPG_Engine.h"
int main()
{
    RPG_Engine Game;
    if (Game.Construct(256, 240, 3, 3));
    Game.Start();
    return 0;
}