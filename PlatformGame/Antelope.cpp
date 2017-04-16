#pragma once
#include "Antelope.h"
#include "World.h"

Antelope::Antelope(int x, int y, World * world) :Animal(x, y, world)
{
	this->name = "Antelope";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 'a';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Antelope::Antelope(World * world) :Animal(world)
{
	this->name = "Antelope";
	this->initative = 1;
	this->strength = 2;
	this->symbol = 'a';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

bool Antelope::isPushBackAttack(Organism* attacker)
{
	if (attacker->getName() == this->name)
	{
		Multiplication();
		return false;
	}
	else if (attacker->getStrength() >= this->getStrength())
	{
		this->isAlive = false;
		return false;
	}	
	else
	{
		attacker->setIsAlive(false);
		return true;
	}
}

void Antelope::Multiplication()
{	
	bool isMoved = false;
	while (!isMoved)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Antelope(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}	
}

void Antelope::action()
{
	bool isMoved;
	for (int i = 0; i < 2; i++)
	{
		isMoved = false;
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