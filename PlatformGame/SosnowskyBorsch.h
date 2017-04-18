#ifndef SOSNOWSKYBORSCH_H
#define SOSNOWSKYBORSCH_H
#include "Plant.h"
class Plant;

class SosnowskyBorsch :public Plant
{
public:

	SosnowskyBorsch(int x, int y, World * world);
	SosnowskyBorsch(World * world);
	void action();
	bool isPushBackAttack(Organism * attacker);
private:
	void Multiplication();
};

#endif // !SOSNOWSKYBORSCH_H

