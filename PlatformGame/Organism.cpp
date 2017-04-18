#pragma once
#include "Organism.h"
#include "World.h"

int Organism::getStrength()
{
	return this->strength;
}

void Organism::setStrength(int value)
{
	this->strength = value;
}

int Organism::getInitative()
{
	return this->initative;
}

int Organism::getX()
{
	return this->x;
}

int Organism::getY()
{
	return this->y;
}

std::string Organism::getName()
{
	return this->name;
}

bool Organism::getIsAlive()
{
	return this->isAlive;
}

void Organism::setX(int x)
{
	this->x = x;
}

void Organism::setY(int y)
{
	this->y = y;
}

void Organism::setIsAlive(bool status)
{
	this->isAlive = status;
	if (!status)
	{
		this->world->getGrid()->setNewMessage(this->getName() + " is dead.");
		this->world->getGrid()->deleteObject(this->x, this->y);
	}
}

bool Organism::compareTwoOrganismPointers(Organism * a, Organism * b)
{
	return (a->initative < b->initative);
}

void Organism::draw(int x, int y)
{
	world->getGrid()->deleteObject(this->x, this->y);
	world->getGrid()->setObject(x, y, this->symbol);
	this->x = x;
	this->y = y;
}

bool Organism::isPushBackAttack(Organism* attacker)
{
	if (attacker->getStrength() >= this->getStrength())
	{
		this->setIsAlive(false);
		return false;
	}
	else
	{
		attacker->setIsAlive(false);
		return true;
	}
}

Organism::Organism(int x, int y, World* world)
{		
	this->isAlive = true;
	this->world = world;
	this->x = x;
	this->y = y;	
}

int* Organism::newRandomPositionAround()
{
	int newX;
	int newY;
	int direction = rand() % 8;
	switch (direction)
	{
	case 0:
	{
		newX = this->x;
		newY = this->y + 1;
		break;
	}
	case 1:
	{
		newX = this->x + 1;
		newY = this->y + 1;
		break;
	}
	case 2:
	{
		newX = this->x + 1;
		newY = this->y;
		break;
	}
	case 3:
	{
		newX = this->x + 1;
		newY = this->y - 1;
		break;
	}
	case 4:
	{
		newX = this->x;
		newY = this->y - 1;
		break;
	}
	case 5:
	{
		newX = this->x - 1;
		newY = this->y - 1;
		break;
	}
	case 6:
	{
		newX = this->x - 1;
		newY = this->y;
		break;
	}
	case 7:
	{
		newX = this->x - 1;
		newY = this->y + 1;
		break;
	}
	default:
		break;
	}
	int* newPositionTab = (int*)malloc(2 * sizeof(int));
	newPositionTab[0] = newX;
	newPositionTab[1] = newY;
	return newPositionTab;
}

Organism::Organism(World * world)
{
	this->isAlive = true;
	this->world = world;
	int *newXY = this->world->GetFreeSpot();
	this->x = newXY[0];
	this->y = newXY[1];
}

Organism::~Organism()
{
	int newNumber = this->world->getNumberOfCreatures() - 1;
	this->world->setNumberoOfCreatures(newNumber);
	this->world->getGrid()->deleteObject(this->x, this->y);
}
