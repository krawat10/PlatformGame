#pragma once
#include "Plant.h"


Plant::Plant(int x, int y, World * world) :Organism(x, y, world)
{
	this->initative = 0;
}

Plant::Plant(World * world):Organism(world)
{
	this->initative = 0;
}

Plant::~Plant()
{
}

void Plant::action()
{
	int random = rand() % 4;
	if (random == 0)
	{
		Multiplication();
	}
}


