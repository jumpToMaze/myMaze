#include "stdafx.h"
#include "Beam.hpp"

Beam::Beam(std::string pathToFile, sf::Vector2f coordinatesXY, sf::Vector2f widthAndLength)
{
	texture = new sf::Texture;
	texture->loadFromFile(pathToFile);
	texture->setSmooth(true);

	shape = new sf::RectangleShape(widthAndLength);
	shape->setPosition(coordinatesXY);
	shape->setTexture(texture);
}

void Beam::changeTexture(std::string pathToFile)
{
	texture->loadFromFile(pathToFile);
	shape->setTexture(texture);
}

Beam::~Beam()
{
	delete texture;
	delete shape;
}

void Beam::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*shape);
}
