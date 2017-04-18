#ifndef ANIMAL_H
#define ANIMAL_H

class Organism;

#include "Organism.h"


class Animal :public Organism
{
public:
	Animal(int x, int y, World* world);
	Animal(World* world);
	virtual void action();
	bool isPushBackAttack(Organism * attacker);
protected:
	virtual void Multiplication() = 0;
	virtual bool attack(int enemyX, int enemyY);
};

#endif // !ANIMALS_H
