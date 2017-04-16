#ifndef CYBERSHEEP_H
#define CYBERSHEEP
#include "Animal.h"
class Animal;

class CyberSheep :public Animal
{
public:
	CyberSheep(int x, int y, World * world);
	CyberSheep(World * world);
	void Multiplication();
	~CyberSheep();
	void draw();
private:

};
#endif // !CYBERSHEEP_H

