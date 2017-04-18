#include "SowThistle.h"
#include "World.h"

SowThistle::SowThistle(int x, int y, World* world) :Plant(x, y, world)
{
	this->name = "SowThistle";
	this->symbol = '$';
	this->world->getGrid()->setObject(x, y, this->symbol);

}

SowThistle::SowThistle(World * world) :Plant(world)
{
	this->name = "SowThistle";
	this->symbol = '$';
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void SowThistle::action()
{
	int random;
	for (int i = 0; i < 3; i++)
	{
		random = rand() % 8;
		if (random == 0)
		{
			Multiplication();
		}
	}	
}

void SowThistle::Multiplication()
{
	int i = 8;
	bool isNewSpot = false;
	while (!isNewSpot && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new SowThistle(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}