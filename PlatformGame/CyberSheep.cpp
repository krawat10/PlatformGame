#pragma once
#include "CyberSheep.h"
#include "World.h"

CyberSheep::CyberSheep(int x, int y, World * world) :Animal(x, y, world)
{
	this->name = "CyberSheep";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 'S';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

CyberSheep::CyberSheep(World * world) :Animal(world)
{
	this->name = "CyberSheep";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 'S';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void CyberSheep::Multiplication()
{
	bool isMoved = false;
	while (!isMoved)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new CyberSheep(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}

void CyberSheep::draw()
{
}