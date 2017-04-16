#pragma once
#include "Human.h"
#include "World.h"
#include "Animal.h"
#define LEFT 'a'
#define RIGHT 'd'
#define UP 's'
#define DOWN 'w'


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
	this->name = "Human";
	this->initative = 4;
	this->strength = 5;
	this->symbol = 'h';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Human::Multiplication()
{
}

Human::~Human()
{
}

void Human::action(char direcrion)
{
	int newX;
	int newY;

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
