#include "Grass.h"
#include "World.h"

Grass::Grass(int x, int y, World* world) :Plant(x, y, world)
{
	this->name = "Grass";
	this->symbol = '#';
	this->world->getGrid()->setObject(x, y, this->symbol);

}

Grass::Grass(World * world) :Plant(world)
{
	this->name = "Grass";
	this->symbol = '#';
	this->world->getGrid()->setObject(x, y, this->symbol);
}



void Grass::Multiplication()
{
	int i = 8;
	bool isNewSpot = false;
	while (!isNewSpot && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Grass(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}


