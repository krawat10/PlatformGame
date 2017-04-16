#ifndef ANTELOPE_H
#define ANTELOPE_H
#include "Animal.h"
class Animal;

class Antelope :public Animal
{
public:
	Antelope(int x, int y, World * world);
	Antelope(World * world);
	bool isPushBackAttack(Organism * attacker);
	void Multiplication();
	void action();
	~Antelope();
private:

};
#endif // !ANTELOPE_H

