#include "Wolfberry.h"
#include "World.h"

Wolfberry::Wolfberry(int x, int y, World* world) :Plant(x, y, world)
{
	this->name = "Wolfberry";
	this->symbol = '^';
	this->strength = 99;
	this->world->getGrid()->setObject(x, y, this->symbol);

}

Wolfberry::Wolfberry(World * world) :Plant(world)
{
	this->name = "Wolfberry";
	this->symbol = '^';
	this->strength = 99;
	this->world->getGrid()->setObject(x, y, this->symbol);
}

void Wolfberry::Multiplication()
{
	int i = 8;
	bool isNewSpot = false;
	while (!isNewSpot && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Wolfberry(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}

bool Wolfberry::isPushBackAttack(Organism* attacker)
{
		this->setIsAlive(false);
		attacker->setIsAlive(false);
		return true;
}
