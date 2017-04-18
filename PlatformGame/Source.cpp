
using namespace std;

#include "World.h"
#include "Grass.h"
#include "Wolf.h"
#include "Human.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "SosnowskyBorsch.h"
#include "CyberSheep.h"
#include "Guarana.h"
#include "Sheep.h"
#include "SowThistle.h" 
#include "Wolfberry.h"
int main()
{	
	World world = World(17, 17);
	world.addCreature(new Wolf(1, 1, &world));
	world.addCreature(new Grass(4, 1, &world));
	world.addCreature(new Human(&world));
	world.addCreature(new Fox(&world));
	world.addCreature(new Turtle(&world));
	world.addCreature(new Antelope(&world));
	world.addCreature(new CyberSheep(&world));
	world.addCreature(new Guarana(&world));
	world.addCreature(new Sheep(&world));
	//world.addCreature(new SowThistle(&world));
	world.addCreature(new Wolfberry(&world));
	world.addCreature(new SosnowskyBorsch(&world));
	world.drawWorld();
}