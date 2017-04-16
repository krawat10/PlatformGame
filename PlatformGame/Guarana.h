#ifndef GUARANA_H
#define GUARANA_H
#include "Plant.h"
class Plant;

class Guarana :public Plant
{
public:

	Guarana(int x, int y, World * world);
	bool isPushBackAttack(Organism * attacker);
	Guarana(World * world);
	~Guarana();
	void collision();
	void Multiplication();
	void draw();
private:

};

#endif // !GUARANA_H

