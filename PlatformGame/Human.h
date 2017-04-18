#ifndef HUMAN_H
#define HUMAN_H
#include "Animal.h"

class Animal;

class Human : public Animal
{
public:
	Human(int x, int y, World* world);
	Human(World* world);
	bool isPushBackAttack(Organism * attacker);
	void action();
private:
	void Multiplication();
	int AlzureShieldTour;
	bool AlzureShield;
};


#endif // !HUMAN_H

