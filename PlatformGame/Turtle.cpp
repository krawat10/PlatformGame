#pragma once
#include "Turtle.h"
#include "World.h"
#include <cstdlib>

Turtle::Turtle(int x, int y, World * world) :Animal(x, y, world)
{
	this->name = "Turtle";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 't';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Turtle::Turtle(World * world) :Animal(world)
{
	this->name = "Turtle";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 't';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Turtle::Multiplication()
{
	bool isMoved = false;
	while (!isMoved)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Turtle(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}

bool Turtle::isPushBackAttack(Organism* attacker)
{
	if (attacker->getStrength() >= 5)
	{
		this->isAlive = false;
		return false;
	}
	else if (attacker->getName() == this->name)
	{
		Multiplication();
		return false;
	}
	else
	{		
		return true;
	}
}


void Turtle::action()
{
	bool isMoved = false;
	int isTired = std::rand() % 3;
	while ((!isMoved) && (isTired == 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->draw(newXY[0], newXY[1]);
			isMoved = true;
		}
		else if (this->world->checkPosition(newXY[0], newXY[1]) == 'm')
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
