#ifndef FOX_H
#define FOX_H
#include "Animal.h"
class Animal;

class Fox :public Animal
{
public:
	Fox(int x, int y, World * world);
	Fox(World * world);
	void action();
private:
	void Multiplication();
};

#endif // !FOX_H
