#pragma once
#ifndef Player_hpp
#define Player_hpp
#include <SFML\Graphics.hpp>

class Maze;
class Player : public sf::Drawable
{
public:
	Player();
	~Player();

	// Up : 1, Down : 2, Left : 3, Right : 4 
	void move(int move, Maze& maze);
	std::string toString();

	sf::Sprite* player;
private:
	sf::Texture *graphicOfPlayer;
	sf::Vector2u* textureSize;
	
	void changeTextureTemp(float x, float y);
	void changeTexture(float x, float y);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !Player_h
