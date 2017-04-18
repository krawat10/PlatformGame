#ifndef SOWTHISTLE_H
#define SOWTHISTLE

#include "Plant.h"
class Plant;

class SowThistle :public Plant
{
public:

	SowThistle(int x, int y, World * world);
	SowThistle(World * world);
	void action();
private:
	void Multiplication();
};
#endif // !SOWTHISTLE_H
