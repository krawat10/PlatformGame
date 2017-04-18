#pragma once
#include "Sheep.h"
#include "World.h"

Sheep::Sheep(int x, int y, World * world) :Animal(x, y, world)
{
	this->name = "Sheep";
	this->initative = 4;
	this->strength = 4;
	this->symbol = 's';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Sheep::Sheep(World * world) :Animal(world)
{
	this->name = "Sheep";
	this->initative = 4;
	this->strength = 4;
	this->symbol = 's';
	this->world->getGrid()->setObject(x, y, this->symbol);
}
void Sheep::Multiplication()
{
	int i = 8;
	bool isMoved = false;
	while (!isMoved && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Sheep(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}
