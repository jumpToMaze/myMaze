#include "stdafx.h"
#include "Maze.hpp"
#include "Beam.hpp"

// default constructor load first maze
Maze::Maze()
{
	Beam *first = new Beam(BEAMPATH, sf::Vector2f(31, 340), sf::Vector2f(280, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(495, 340), sf::Vector2f(277, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(125, 260), sf::Vector2f(370, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(217, 180), sf::Vector2f(185, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(403, 100), sf::Vector2f(368, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(31, 20), sf::Vector2f(14.8*X, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(31, 420), sf::Vector2f(14.8 * X, BEAMWIDTH));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(31, 20), sf::Vector2f(BEAMWIDTH, 8.1*X));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(767, 20), sf::Vector2f(BEAMWIDTH, 8.1 * X));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(120, 100), sf::Vector2f(BEAMWIDTH, 165));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(215, 100), sf::Vector2f(BEAMWIDTH, 85));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(400, 100), sf::Vector2f(BEAMWIDTH, 85));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(398, 263), sf::Vector2f(BEAMWIDTH, 160));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(582, 185), sf::Vector2f(BEAMWIDTH, 160));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(675, 105), sf::Vector2f(BEAMWIDTH, 160));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(305, 20), sf::Vector2f(BEAMWIDTH, 80));
	addNewBeam(first);

	first = new Beam(BEAMPATH, sf::Vector2f(495, 185), sf::Vector2f(BEAMWIDTH, 80));
	addNewBeam(first);
}

void Maze::addNewBeam(Beam *&beam)
{
	beams.push_back(beam);
}

Beam* Maze::getBeamNumber(int number)
{
	return beams[number];
}

Maze::~Maze()
{
	for (int i = 0; i < beams.size(); i++)
		delete beams[i];

	beams.clear();
}

void Maze::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < beams.size(); i++)
		target.draw(*beams[i]);
}
