#include "stdafx.h"
#include "Interface.h"
#include "Player.h"
#include "Maze.hpp"
#include "constant.hpp"
#include "TimeManagement.h"
#include "ObjectOnMap.h"
#include "Trophy.h"
#include "constant.hpp"
#include "Collision.h"


Interface::Interface()
{
	hero = new Player();
	
	actualMaze = new Maze();
	
	background = new ObjectOnMap(BACKGROUNDPATH, sf::Vector2f(0, 0), sf::Vector2f(WINDOWWIDTH, WINDOWHEIGHT));
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIASINGLEVEL;


	mainWindow = new sf::RenderWindow(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), WINDOWNAME,sf::Style::Default, settings);
	mainWindow->setVerticalSyncEnabled(true);
	mainWindow->setFramerateLimit(FRAMELIMIT);


	clock = new TimeManagement();
	
	font = new sf::Font();
	font->loadFromFile(FONTPATH);
	
	clock->timeRestart();
	
	loadTexts();
	loadLabels();
}

void Interface::update()
{
	moveHero();
	drawObjects();
	if (collectedAllTrophy())
		loadFinalWindow();
}

bool Interface::endOfGame()
{
	return collectedAllTrophy() || isClosedWindow();
}


void Interface::moveHero()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) 
	 || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		hero->move(LEFT, *actualMaze);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		hero->move(RIGHT, *actualMaze);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		hero->move(UP, *actualMaze);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		hero->move(DOWN, *actualMaze);

	} 
	
	isClosedWindow();

	updateCounter();
}

void Interface::drawObjects()
{
	mainWindow->clear(sf::Color::White);
	
	mainWindow->draw(*background);

	for (int i = 0; i < texts.size(); i++)
		mainWindow->draw(*texts[i]);

	for (int i = 0; i < labels.size(); i++)
		mainWindow->draw(*labels[i]);

	mainWindow->draw(clock->loadTimeToText());

	mainWindow->draw(loadAmountOfTrophyToText());

	mainWindow->draw(*actualMaze);
	
	mainWindow->draw(*hero);

	mainWindow->display();
}

bool Interface::collectedAllTrophy()
{
	return labels.size() == 0;
}

void Interface::loadTexts()
{
	sf::Text* text = new sf::Text;


	text->setFont(*font);
	text->setString(TIMESTRING);
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(SIDEMENUTIMECHARSIZE); 
	text->setStyle(sf::Text::Bold);
	text->setPosition(SIDEMENUTIMESTRINGX, SIDEMENUTIMESTRINGY);

	texts.push_back(text);

	text = new sf::Text;
	text->setFont(*font);
	text->setString(TROPHYNAME);
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(SIDEMENUTROPHYCHARSIZE);
	text->setPosition(SIDEMENUTROPHYSTRINGX, SIDEMENUTROPHYSTRINGY);

	texts.push_back(text);
}

sf::Text Interface::loadAmountOfTrophyToText()
{
	sf::Text text;
	text.setFont(*font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(SIDEMENUTROPHYAMOUNTCHARSIZE);
	text.setPosition(SIDEMENUTROPHYAMOUTSTRINGX, SIDEMENUTROPHYAMOUNTSTRINGY);

	text.setString(std::to_string(labels.size()));

	return text;
}

void Interface::loadLabels()
{
	Trophy* trophy = new Trophy(TROPHYPATH, sf::Vector2f(70, 50));
	labels.push_back(trophy);

	trophy = new Trophy(TROPHYPATH, sf::Vector2f(710, 150));
	labels.push_back(trophy);

	trophy = new Trophy(TROPHYPATH, sf::Vector2f(710, 50));
	labels.push_back(trophy);

	trophy = new Trophy(TROPHYPATH, sf::Vector2f(70, 370));
	labels.push_back(trophy);
}

void Interface::updateCounter()
{
	Collision collision(hero->player);
	for (int i = 0; i < labels.size(); i++) {
		if (collision.isCollisionWithTrophy(*labels[i])) {
			labels.erase(labels.begin() + i);
			i--;
		}
	}
}

void Interface::loadFinalWindow()
{
	mainWindow->clear(sf::Color::Green);
	mainWindow->draw(clock->loadFinalTime());

	mainWindow->display();

	sf::Clock cWait;
	sf::Time tWait;
	tWait = cWait.getElapsedTime();
	int i = 10;
	while(tWait.asSeconds() < i){
		if (isClosedWindow())
			i = 0;
		tWait = cWait.getElapsedTime();
	}

	mainWindow->close();
}

bool Interface::isClosedWindow()
{
	bool result = false;
	sf::Event event;
	mainWindow->pollEvent(event);
	if (event.type == sf::Event::Closed) {
		mainWindow->close();
		result = true;
	}

	return result;
}

Interface::~Interface()
{
	delete hero;
	delete actualMaze;
	
	for (int i = 0; i < texts.size(); i++)
		delete texts[i];
	texts.clear();

	for (int i = 0; i < labels.size(); i++)
		delete labels[i];
	labels.clear();

	delete font;
	delete clock;
	delete background;
	delete mainWindow;
}