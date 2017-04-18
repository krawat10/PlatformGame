#pragma once
#include "Human.h"
#include "World.h"
#include "Animal.h"
#define LEFT 75
#define RIGHT 77
#define UP 80
#define DOWN 72
#define SHIELD 'p'


Human::Human(int x, int y, World* world) :Animal(x, y, world)
{
	this->name = "Human";
	this->initative = 4;
	this->strength = 5;
	this->symbol = 'h';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

Human::Human(World * world) :Animal(world)
{
	this->AlzureShield = false;
	this->AlzureShieldTour = 0;
	this->name = "Human";
	this->initative = 4;
	this->strength = 5;
	this->symbol = 'h';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Human::Multiplication()
{
}

bool Human::isPushBackAttack(Organism* attacker)
{
	if (this->AlzureShield)
	{
		int i = 8;
		bool isNewSpot = false;
		while (!isNewSpot && (i-- != 0))
		{
			int* newXY = this->newRandomPositionAround();
			if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
			{				
				attacker->draw(newXY[0], newXY[1]);
				isNewSpot = true;
			}
		}		
		return true;
	}
	else if (attacker->getStrength() >= this->getStrength())
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

void Human::action()
{
	char direcrion = this->world->getImput();
	int newX;
	int newY;
	this->AlzureShieldTour--;
	if ((this->AlzureShieldTour == 0) && this->AlzureShield)
	{
		this->AlzureShield = false;
		this->world->getGrid()->setNewMessage("Alzure Shield deactivated.");
	}

	switch (direcrion)
	{
	case DOWN:
	{
		newX = this->x;
		newY = this->y - 1;
		break;
	}
	case UP:
	{
		newX = this->x;
		newY = this->y + 1;
		break;
	}
	case LEFT:
	{
		newX = this->x - 1;
		newY = this->y;
		break;
	}
	case RIGHT:
	{
		newX = this->x + 1;
		newY = this->y;
		break;
	}
	case SHIELD:
	{
		if (this->AlzureShieldTour <= -5)
		{
			this->AlzureShield = true;
			this->AlzureShieldTour = 5;
			this->world->getGrid()->setNewMessage("Azure shield activated!");
		}		
	}
	default:
		return;
	}

	if (this->world->checkPosition(newX, newY) == 'o')
	{
		this->draw(newX, newY);
	}
	else if (this->world->checkPosition(newX, newY) == 'm')
	{
		if (this->attack(newX, newY))
		{
			this->draw(newX, newY);
		}
		else
			return;


	}
}
