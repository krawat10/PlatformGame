#include "Guarana.h"
#include "World.h"

Guarana::Guarana(int x, int y, World* world) :Plant(x, y, world)
{
	this->name = "Guarana";
	this->symbol = '+';
	this->world->getGrid()->setObject(x, y, this->symbol);

}

bool Guarana::isPushBackAttack(Organism* attacker)
{
	int newStrength = attacker->getStrength() + 3;
	attacker->setStrength(newStrength);
	this->setIsAlive(false);
	return false;
}

Guarana::Guarana(World * world) :Plant(world)
{
	this->name = "Guarana";
	this->symbol = '+';
	this->world->getGrid()->setObject(x, y, this->symbol);
}




void Guarana::Multiplication()
{
	int i = 8;
	bool isNewSpot = false;
	while (!isNewSpot && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new Guarana(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}
