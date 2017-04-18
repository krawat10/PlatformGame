#ifndef TURTLE_H
#define TURTLE_H
#include "Animal.h"
class Animal;

class Turtle :public Animal
{
public:
	Turtle(int x, int y, World * world);
	Turtle(World * world);
	bool isPushBackAttack(Organism * attacker);
	void action();
private:
	void Multiplication();
};

#endif // !TURTLE_H
