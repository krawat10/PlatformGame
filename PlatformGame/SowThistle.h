#ifndef SOWTHISTLE_H
#define SOWTHISTLE

#include "Plant.h"
class Plant;

class SowThistle :public Plant
{
public:

	SowThistle(int x, int y, World * world);
	SowThistle(World * world);
	~SowThistle();
	void collision();
	void Multiplication();
	void draw();
private:

};
#endif // !SOWTHISTLE_H
