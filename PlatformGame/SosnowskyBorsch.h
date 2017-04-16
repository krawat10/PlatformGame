#ifndef SOSNOWSKYBORSCH_H
#define SOSNOWSKYBORSCH_H
#include "Plant.h"
class Plant;

class SosnowskyBorsch :public Plant
{
public:

	SosnowskyBorsch(int x, int y, World * world);
	SosnowskyBorsch(World * world);
	~SosnowskyBorsch();
	void action();
	void Multiplication();
	bool isPushBackAttack(Organism * attacker);
	void draw();
private:

};

#endif // !SOSNOWSKYBORSCH_H

