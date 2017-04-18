#ifndef PLANT_H
#define PLANT_H

class Organism;

#include "Organism.h"


class Plant:public Organism
{
public:
	Plant(int x, int y, World* world);
	Plant(World* world);
	virtual void action();
private:
	virtual void Multiplication() = 0;
};

#endif // !PLANT_H
