#ifndef CYBERSHEEP_H
#define CYBERSHEEP
#include "Animal.h"
class Animal;

class CyberSheep :public Animal
{
public:
	CyberSheep(int x, int y, World * world);
	CyberSheep(World * world);	
	void action();	
private:
	void Multiplication();
};
#endif // !CYBERSHEEP_H

