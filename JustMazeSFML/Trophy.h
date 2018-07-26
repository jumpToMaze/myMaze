#ifndef Trophy_h
#define Trophy_h
#include <SFML\Graphics.hpp>

class Collision;

class Trophy : public sf::Drawable{
	friend class Collision;
public:
	Trophy(std::string fileName, sf::Vector2f coordinates);
	~Trophy();
private:
	sf::RectangleShape* trophyShape;
	sf::Texture* texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // !Trophy_h