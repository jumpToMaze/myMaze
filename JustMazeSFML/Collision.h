#ifndef Collision_h
#define Collision_h
#include <SFML\Graphics.hpp>

class Maze;
class Trophy;

class Collision
{
public:
	Collision(sf::Sprite*& shape);
	~Collision() {};

	bool isCollisionWithMaze(Maze &maze);
	bool isCollisionWithTrophy(Trophy& trophy);

private:
	sf::Sprite thisShape;
};

#endif // !Collision_h