#include <iostream>

using namespace std;
#include "Grid.h"
#include "World.h"
#include "Grass.h"
#include "Wolf.h"
#include "Human.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "SosnowskyBorsch.h"
int main()
{	
	World world = World(15, 15);
	world.addCreature(new Wolf(1, 1, &world));
	world.addCreature(new Grass(1, 1, &world));
	world.addCreature(new Wolf(4, 2, &world));
	world.addCreature(new Grass(6, 3, &world));
	world.addCreature(new Wolf(6, 4, &world));
	world.addCreature(new Grass(6, 5, &world));
	world.addCreature(new Wolf(&world));
	world.addCreature(new Grass(&world));
	world.addCreature(new Human(&world));
	world.addCreature(new Fox(&world));
	world.addCreature(new Fox(&world));
	world.addCreature(new Fox(&world));
	world.addCreature(new Turtle(&world));
	world.addCreature(new Turtle(&world));
	world.addCreature(new Antelope(&world));
	world.addCreature(new Antelope(&world));
	world.addCreature(new SosnowskyBorsch(&world));
	world.drawWorld();
}