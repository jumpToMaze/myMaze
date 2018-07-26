#ifndef  Beam_hpp
#define Beam_hpp
#include <SFML\Graphics.hpp>

class Collision;

class Beam : public sf::Drawable {
	friend class Collision;
public:
	Beam(std::string pathToFile, sf::Vector2f coordinatesXY, sf::Vector2f widthAndLength);

	void changeTexture(std::string pathToFile);

	~Beam();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Texture* texture;
	sf::RectangleShape* shape;

};

#endif // ! Beam_hpp

