#include "stdafx.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include "Collision.h"
#include "constant.hpp"

using namespace std;

Player::Player()
{
	graphicOfPlayer = new sf::Texture;
	graphicOfPlayer->loadFromFile(HEROPATH);
	graphicOfPlayer->setSmooth(true);

	player = new sf::Sprite(*graphicOfPlayer);
	player->setPosition(sf::Vector2f(710, 360));

	player->setTexture(*graphicOfPlayer);

	textureSize = new sf::Vector2u(graphicOfPlayer->getSize());
	textureSize->x /= CORX;
	textureSize->y /= CORY;

	player->setTextureRect(sf::IntRect(textureSize->x + STARTCUTFROMX, textureSize->y * STARTANIMATION + STARTCUTFROMY, HEROWIDTH, HEROHEIGHT));

	player->setScale(SCALEX, SCALEY);	
}


Player::~Player()
{
	delete textureSize;
	delete player;
	delete graphicOfPlayer;
}

void Player::move(int move, Maze& maze)
{
	float oldX = player->getPosition().x;
	float oldY = player->getPosition().y;

	if (move == UP) {
		player->move(0, -SPEED);
		Collision collision(player);
		int i = 1;
		if (collision.isCollisionWithMaze(maze))
			while (collision.isCollisionWithMaze(maze)) {
				player->move(0, i);
				collision = Collision(player);

			}
	}
	if (move == DOWN) {
		player->move(0, SPEED);
		Collision collision(player);
		int i = 1;
		if (collision.isCollisionWithMaze(maze))
			while (collision.isCollisionWithMaze(maze)) {
				player->move(0, -i);
				collision = Collision(player);

			}
	}
	if (move == LEFT) {
		player->move(-SPEED, 0);
		Collision collision(player);
		int i = 1;
		if (collision.isCollisionWithMaze(maze))
			while (collision.isCollisionWithMaze(maze)) {
				player->move(i, 0);
				collision = Collision(player);

			}
	}
	if (move == RIGHT) {
		player->move(SPEED, 0);
		Collision collision(player);
		int i = 1;
		if (collision.isCollisionWithMaze(maze))
			while (collision.isCollisionWithMaze(maze)) {
				player->move(-i, 0);
				collision = Collision(player);
			}
	}

	changeTexture(oldX, oldY);
}

void Player::changeTextureTemp(float x, float y)
{
	player->setTextureRect(sf::IntRect(textureSize->x * x + STARTCUTFROMX, textureSize->y*y + STARTCUTFROMY, HEROWIDTH, HEROHEIGHT));
}

void Player::changeTexture(float x, float y)
{
	static int nextXF = 0;
	static int nextXB = 0;

	static int nextYU = 0;
	static int nextYD = 0;
	
	if (player->getPosition().x > x) {
			changeTextureTemp(nextXF, 3);
			if (nextXF == 3)
				nextXF = 0;
			else nextXF++;
	}
	else if (player->getPosition().x < x) {
		changeTextureTemp(nextXB, 2);
		if (nextXB == 3)
			nextXB = 0;
		else nextXB++;
	}

	if (player->getPosition().y > y) {
		changeTextureTemp(nextYU, 0);
		if (nextYU == 3)
			nextYU = 0;
		else nextYU++;
	}
	else if (player->getPosition().y < y) {
		changeTextureTemp(nextYD, 1);
		if (nextYD == 3)
			nextYD = 0;
		else nextYD++;
	}
}

std::string Player::toString()
{
	return std::to_string(textureSize->x) + SPACE + std::to_string(textureSize->y);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*player);
}
