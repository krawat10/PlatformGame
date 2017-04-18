#pragma once
#include "Wolf.h"
#include "World.h"

Wolf::Wolf(int x, int y, World * world):Animal(x, y, world)
{
	this->name = "Wolf";
	this->initative = 5;
	this->strength = 9;
	this->symbol = 'w';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Wolf::Wolf(World * world):Animal(world)
{
	this->name = "Wolf";
	this->initative = 5;
	this->strength = 9;
	this->symbol = 'w';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Wolf::Multiplication()
{
	int i = 8;
	bool isMoved = false;
	while (!isMoved && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Wolf(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}

