#ifndef WORLD_H
#define WORLD_H

class Organism;
#include "Grid.h"
#include "Serializable.h"

class World : public Serializable
{
public:
	World(int sizeX, int sizeY);
	~World();
	bool attackMonsterAtPosition(int x, int y, Organism * attacker);
	Organism* getCrature(int x, int y);
	void drawWorld();
	void tour();
	void setNumberoOfCreatures(int number);
	int getNumberOfCreatures();
	void addCreature(Organism* org);
	char checkPosition(int x, int y);
	Grid* getGrid();
	int* GetFreeSpot();
	std::vector<Organism*> getList();
	int getImput();
private:
	virtual void serialize(std::ostream& stream);
	virtual void deserialize(std::istream& stream);
	void save();
	void load();
	void ClearDeadMonster();	
	int sizeX;
	int sizeY;
	int imput;
	int firstimput;
	int numberOfCreatures;
	std::vector<Organism*> organism;
	Grid* grid;

};

#endif // !WORLD_H