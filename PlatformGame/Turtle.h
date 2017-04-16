#ifndef TURTLE_H
#define TURTLE_H
#include "Animal.h"
class Animal;

class Turtle :public Animal
{
public:
	Turtle(int x, int y, World * world);
	Turtle(World * world);
	void Multiplication();
	bool isPushBackAttack(Organism * attacker);
	~Turtle();
	void action();
private:

};

#endif // !TURTLE_H
