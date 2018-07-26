#include "stdafx.h"
#include "Trophy.h"
#include "constant.hpp"

Trophy::Trophy(std::string fileName, sf::Vector2f coordinates)
{
	texture = new sf::Texture;
	texture->loadFromFile(fileName);
	texture->setSmooth(1);

	trophyShape = new sf::RectangleShape(sf::Vector2f(TROPHYSIZEX, TROPHYSIZEY));
	trophyShape->setPosition(coordinates);
	trophyShape->setTexture(texture);
}

Trophy::~Trophy()
{
	delete trophyShape;
	delete texture;
}

void Trophy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*trophyShape);
}
