#ifndef WOLFBERRY_H
#define WOLFBERRY_H
#include "Plant.h"
class Plant;

class Wolfberry :public Plant
{
public:

	Wolfberry(int x, int y, World * world);
	Wolfberry(World * world);
	~Wolfberry();
	void collision();
	void Multiplication();
	void draw();
private:

};

#endif // !WOLFBERRY_H

