#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::start()
{
	while (!gameOver()) {
		update();
	}
}


Game::~Game()
{
}

bool Game::gameOver()
{

	return endOfGame();
}
