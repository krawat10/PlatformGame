#include "SosnowskyBorsch.h"
#include "World.h"
#include "Animal.h"
SosnowskyBorsch::SosnowskyBorsch(int x, int y, World* world) :Plant(x, y, world)
{
	this->name = "SosnowskyBorsch";
	this->symbol = 'X';
	this->strength = 10;
	this->world->getGrid()->setObject(x, y, this->symbol);

}

SosnowskyBorsch::SosnowskyBorsch(World * world) :Plant(world)
{
	this->name = "SosnowskyBorsch";
	this->symbol = 'X';
	this->strength = 10;
	this->world->getGrid()->setObject(x, y, this->symbol);
}


void SosnowskyBorsch::action()
{
	int random = rand() % 8;
	if (random == 0)
	{
		Multiplication();
	}
	int newX, newY;
	for (int direction = 0; direction < 8; direction++)
	{
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
		if (world->checkPosition(newX, newY)== 'm')
		{
			Organism* org = world->getCrature(newX, newY);
			
			if (dynamic_cast<Animal*>(org) != NULL)
			{
				if (org->getName() != "CyberSheep" && (org->getName() != this->getName()))
				{
					org->setIsAlive(false);
					world->getGrid()->deleteObject(org->getX(), org->getY());
				}
			}			
		}
	}

}

void SosnowskyBorsch::Multiplication()
{
	int i = 8;
	bool isNewSpot = false;
	while (!isNewSpot && (i-- != 0))
	{
		int* newXY = this->newRandomPositionAround();
		if (this->world->checkPosition(newXY[0], newXY[1]) == 'o')
		{
			this->world->addCreature(new SosnowskyBorsch(newXY[0], newXY[1], this->world));
			isNewSpot = true;
		}
	}
}

bool SosnowskyBorsch::isPushBackAttack(Organism* attacker)
{
	if (attacker->getName() == "CyberSheep")
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
