#ifndef ORGANISM_H	
#define ORGANISM_H
#include <string>
//
//It gives information that class World exist. In .cpp files is included World header to 
//get access to World fields.
//
class World;



class Organism
{
public:
	Organism(int x, int y, World* world);
	
	Organism(World* world);
	~Organism();
	int getStrength();
	void setStrength(int value);
	int getInitative();
	int getX();
	int getY();
	std::string getName();
	bool getIsAlive();
	void setX(int x);
	void setY(int y);
	void setIsAlive(bool status);
	virtual void action() = 0;
	static bool compareTwoOrganismPointers(Organism* a, Organism* b);
	virtual bool isPushBackAttack(Organism * attacker);
protected:
	int * newRandomPositionAround();
	void draw(int x, int y);
	bool isAlive;
	World* world;
	int strength;
	int initative;
	char symbol;
	int x;
	int y;
	static int counter;
	std::string name;
};



#endif // !WORLD_H