#include "stdafx.h"
#include "TimeManagement.h"
#include "constant.hpp"

TimeManagement::TimeManagement()
{
	font.loadFromFile(FONTPATH);
	clock.restart();
}

void TimeManagement::timeRestart()
{
	clock.restart();
}

int TimeManagement::timeInSeconds()
{
	time = clock.getElapsedTime();
	return time.asSeconds();
}

sf::Text TimeManagement::loadTimeToText()
{
	sf::Text textClock;
	textClock.setFont(font);
	textClock.setFillColor(sf::Color::Black);
	textClock.setCharacterSize(TIMEONCLOCKCHARSIZE);
	textClock.setPosition(TIMEONCLOCKPOSX, TIMEONCLOCKPOSY);

	int sec = timeInSeconds();
	if (sec / MINUTEASSECONDS < TEN && sec % MINUTEASSECONDS < TEN)
		textClock.setString(ZEROSTRING + std::to_string((int)(sec / MINUTEASSECONDS)) + SPACE + COLON + SPACE + ZEROSTRING + std::to_string((int)sec % MINUTEASSECONDS));
	else if (sec / MINUTEASSECONDS <TEN)
		textClock.setString(ZEROSTRING + std::to_string((int)(sec / MINUTEASSECONDS)) + SPACE + COLON + SPACE + std::to_string((int)sec % MINUTEASSECONDS));

	return textClock;
}

sf::Text TimeManagement::loadFinalTime()
{
	sf::Text text;
	text.setFont(font);
	text.setString(YOURTIMESTRING + loadTimeToText().getString());
	text.setCharacterSize(50);
	text.setPosition(5 * X, 3 * X);

	return text;
}


TimeManagement::~TimeManagement()
{
}
