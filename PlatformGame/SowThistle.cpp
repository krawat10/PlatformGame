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

SowThistle::~SowThistle()
{
}

void SowThistle::collision()
{
}

void SowThistle::Multiplication()
{
	bool isNewSpot = false;
	while (!isNewSpot)
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new SowThistle(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}

void SowThistle::draw()
{
}