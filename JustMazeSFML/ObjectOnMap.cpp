#include "stdafx.h"
#include "ObjectOnMap.h"

ObjectOnMap::ObjectOnMap(std::string fileName,sf::Vector2f coordinates,sf::Vector2f size)
{
	texture = new sf::Texture;
	texture->loadFromFile(fileName);
	texture->setSmooth(true);

	shape = new sf::RectangleShape(sf::Vector2f(size.x,size.y));
	shape->setPosition(coordinates.x, coordinates.y);
	shape->setTexture(texture);

}

sf::FloatRect ObjectOnMap::getGlobalBounds()
{
	sf::FloatRect temp = shape->getGlobalBounds();
	return temp;
}

sf::RectangleShape* ObjectOnMap::getRectangleShape()
{
	return shape;
}

ObjectOnMap::~ObjectOnMap()
{
	delete shape;
	delete texture;
}

void ObjectOnMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*shape);
}
