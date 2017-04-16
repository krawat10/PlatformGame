#ifndef HUMAN_H
#define HUMAN_H
#include "Animal.h"

class Animal;

class Human : public Animal
{
public:
	Human(int x, int y, World* world);
	Human(World* world);
	void Multiplication();
	~Human();
	void action(char direcrion);
private:

};


#endif // !HUMAN_H

