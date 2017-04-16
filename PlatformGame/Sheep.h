#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"
class Animal;

class Sheep :public Animal
{
public:
	Sheep(int x, int y, World * world);
	Sheep(World * world);
	void Multiplication();
	~Sheep();
	void draw();
private:

};
#endif // !SHEEP_H

