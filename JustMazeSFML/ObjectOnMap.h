#ifndef ObjectOnMap_h
#define ObjectOnMap_h
#include <SFML\Graphics.hpp>


class ObjectOnMap : public sf::Drawable
{
public:
	ObjectOnMap() = delete;
	ObjectOnMap(std::string fileName, sf::Vector2f coordinates, sf::Vector2f size);


	sf::FloatRect getGlobalBounds();
	sf::RectangleShape* getRectangleShape();
	~ObjectOnMap();
private:
	sf::RectangleShape *shape;
	sf::Texture *texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ObjectOnMap_h

