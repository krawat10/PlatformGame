#ifndef GRASS_H
#define GRASS_H

#include "Plant.h"
class Plant;

class Grass:public Plant
{
public:
	
	Grass(int x, int y, World * world);
	Grass(World * world);
	~Grass();
	void collision();
	void Multiplication();
	void draw();
private:

};


#endif // !GRASS_H
