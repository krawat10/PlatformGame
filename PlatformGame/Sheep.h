#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"
class Animal;

class Sheep :public Animal
{
public:
	Sheep(int x, int y, World * world);
	Sheep(World * world);
private:
	void Multiplication();
};
#endif // !SHEEP_H

