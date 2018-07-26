#include "stdafx.h"
#include "Collision.h"
#include "Maze.hpp"
#include "Beam.hpp"
#include "Trophy.h"

Collision::Collision(sf::Sprite*& shape)
{
	thisShape = *shape;
}

bool Collision::isCollisionWithMaze(Maze& maze)
{
	bool result = false;

	sf::FloatRect boundingBox = thisShape.getGlobalBounds();
	sf::FloatRect otherBox;

	for (int i = 0; i < maze.beams.size(); i++) {
		otherBox = maze.beams[i]->shape->getGlobalBounds();
		if (boundingBox.intersects(otherBox)) {
			result = true;
			i = maze.beams.size();
		}
	}

	return result;
}

bool Collision::isCollisionWithTrophy(Trophy& trophy)
{
	bool result = false;

	sf::FloatRect boundingBox = thisShape.getGlobalBounds();
	sf::FloatRect otherBox = trophy.trophyShape->getGlobalBounds();

	if (boundingBox.intersects(otherBox))
		result = true;

	return result;
}
