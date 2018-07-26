#ifndef Interface_h
#define Interface_h

#include <SFML\Graphics.hpp>
#include <vector>

class Maze;
class Player;
class TimeManagement;
class ObjectOnMap;
class Trophy;

class Interface
{
public:
	Interface();
	void update();
	bool endOfGame();

	~Interface();
private:
	Player* hero;
	Maze* actualMaze;
	std::vector<sf::Text*> texts;
	sf::Font* font;
	TimeManagement* clock;
	ObjectOnMap* background;
	std::vector<Trophy*> labels;
	sf::RenderWindow* mainWindow;

	void loadTexts();
	sf::Text loadAmountOfTrophyToText();
	void loadLabels();
	void updateCounter();
	void moveHero();
	void drawObjects();
	void loadFinalWindow();
	bool isClosedWindow();
	bool collectedAllTrophy();
};
#endif // !Interface_h

