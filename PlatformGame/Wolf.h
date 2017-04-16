#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"
class Animal;

class Wolf:public Animal
{
public:
	Wolf(int x, int y, World * world);
	Wolf(World * world);
	void Multiplication();
	~Wolf();
	void draw();

private:

};


#endif // !WOLF_H

