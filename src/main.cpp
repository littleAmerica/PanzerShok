#include "Game.h"
#include <iostream>

int main(int argc, char **argv)
{
    Game game("Test", 200, 200, 840, 480);
	game.run();

	return 0;
}
