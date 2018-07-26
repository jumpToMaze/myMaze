#ifndef Maze_hpp
#define Maze_hpp

#include <SFML\Graphics.hpp>
#include <vector>
#include "constant.hpp"

class Beam;
class Collision;

class Maze : public sf::Drawable {
	friend class Collision;
	friend class Beam;

public:
	Maze();
	void addNewBeam(Beam*& beam);
	Beam* getBeamNumber(int number);

	~Maze();

private:
	std::vector<Beam*> beams;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !Maze_hpp
