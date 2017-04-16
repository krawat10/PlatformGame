#pragma once
#include "Fox.h"
#include "World.h"

Fox::Fox(int x, int y, World * world) :Animal(x, y, world)
{
	this->name = "Fox";
	this->initative = 7;
	this->strength = 3;
	this->symbol = 'f';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Fox::Fox(World * world) :Animal(world)
{
	this->name = "Fox";
	this->initative = 7;
	this->strength = 3;
	this->symbol = 'f';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Fox::action()
{
	bool isMoved = false;
	while (!isMoved)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->draw(newXY[0], newXY[1]);
			isMoved = true;
		}
		else if (this->world->checkPosition(newXY[0], newXY[1]) == 'm')
		{
			Organism *org = this->world->getCrature(newXY[0], newXY[1]);
			if(org->getStrength() < this->initative)
			{ 
			if (this->attack(newXY[0], newXY[1]))
			{
				this->draw(newXY[0], newXY[1]);
				isMoved = true;
			}
			else
				return;
			}
		}
	}
}

void Fox::Multiplication()
{
	bool isMoved = false;
	while (!isMoved)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Fox(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}