#include "Game.h"
#include <iostream>

int main(int argc, char **argv)
{
	Game game("Test", 200, 200, 600, 600);
	game.run();

	return 0;
}