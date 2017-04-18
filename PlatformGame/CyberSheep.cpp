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
	int i = 8;
	bool isMoved = false;
	while (!isMoved && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new CyberSheep(newXY[0], newXY[1], this->world));
			isMoved = true;
		}
	}
}

void CyberSheep::action()
{
	int newX = 0;
	int newY = 0;
	int shortestDistanceToBorsch = 0;
	int currentDistanceToBorsch;
	int currentDirectionX;
	int currentDirectionY;
	std::vector<Organism*> list = world->getList();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getName() == "SosnowskyBorsch")
		{
			int currentDistanceToBorsch = 0;
			int currentDirectionX = 0;
			int currentDirectionY = 0;
			currentDistanceToBorsch = abs(this->getX() - list[i]->getX()) + abs(this->getY() - list[i]->getY());
			if (this->getX() != list[i]->getX())
			{
				currentDirectionX = (this->getX() > list[i]->getX()) ? (-1) : 1;
			}				
			if (this->getY() != list[i]->getY())
			{
				currentDirectionY = (this->getY() > list[i]->getY()) ? (-1) : 1;
			}				
			
			if ((currentDistanceToBorsch < shortestDistanceToBorsch) || shortestDistanceToBorsch == 0)
			{
				shortestDistanceToBorsch = currentDistanceToBorsch;
				newX = this->getX() + currentDirectionX;
				newY = this->getY() + currentDirectionY;
			}
		}
	}

	if (newX == 0 && newY == 0)
	{
		int* newXY = this->newRandomPositionAround();
		newX = newXY[0];
		newY = newXY[1];
	}
	bool isMoved = false;
	while (!isMoved)
	{
		
		if (this->world->checkPosition(newX, newY) == 'o')
		{
			this->draw(newX, newY);
			isMoved = true;
		}
		else if (this->world->checkPosition(newX, newY) == 'm')
		{
			if (this->attack(newX, newY))
			{
				this->draw(newX, newY);
				isMoved = true;
			}
			else
				return;
		}
		int* newXY = this->newRandomPositionAround();
		newX = newXY[0];
		newY = newXY[1];
	}
}