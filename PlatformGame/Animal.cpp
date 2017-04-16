#pragma once
#include "Animal.h"
#include "World.h"
#include "Grid.h"
#include <cstdlib>
Animal::Animal(int x, int y, World * world):Organism(x, y, world)
{

}
Animal::Animal(World * world):Organism(world)
{
}
Animal::~Animal()
{
}

void Animal::action()
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

bool Animal::isPushBackAttack(Organism* attacker)
{
	if (attacker->getName() == this->name)
	{
		Multiplication();
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

bool Animal::attack(int enemyX, int enemyY)
{
	return this->world->attackMonsterAtPosition(enemyX, enemyY, this);
}

void Animal::collision()
{
}
