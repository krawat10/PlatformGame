#ifndef WOLFBERRY_H
#define WOLFBERRY_H
#include "Plant.h"
class Plant;

class Wolfberry :public Plant
{
public:

	Wolfberry(int x, int y, World * world);
	Wolfberry(World * world);
	bool isPushBackAttack(Organism * attacker);
private:
	void Multiplication();
};

#endif // !WOLFBERRY_H

