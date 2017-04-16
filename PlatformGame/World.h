#ifndef WORLD_H
#define WORLD_H

class Organism;
#include <vector>
#include "Grid.h"


class World
{
public:
	World(int sizeX, int sizeY);
	~World();
	bool attackMonsterAtPosition(int x, int y, Organism * attacker);
	Organism* getCrature(int x, int y);
	void drawWorld();
	void setNumberoOfCreatures(int number);
	int getNumberOfCreatures();
	void addCreature(Organism* org);
	char checkPosition(int x, int y);
	Grid* getGrid();
	int* GetFreeSpot();
private:
	void ClearDeadMonster();	
	int sizeX;
	int sizeY;
	int numberOfCreatures;
	std::vector<Organism*> organism;
	Grid* grid;

};

#endif // !WORLD_H