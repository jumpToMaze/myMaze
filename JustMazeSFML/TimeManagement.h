#ifndef TimeManagement_h
#define	TimeManagement_h
#include <SFML\Graphics.hpp>

class TimeManagement
{
public:
	TimeManagement();
	void timeRestart();
	
	sf::Text loadTimeToText();
	sf::Text loadFinalTime();

	~TimeManagement();

private:
	sf::Font font;
	sf::Time time;
	sf::Clock clock;

	int timeInSeconds();
};

#endif // !TimeManagement_h

