#pragma once 

#include <iostream>
#include <algorithm>
#include <random>
#include <conio.h>
#include <iostream>
#include "World.h"
#include "Human.h"
#include "Antelope.h"
#include "CyberSheep.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sheep.h"
#include "SosnowskyBorsch.h"
#include "SowThistle.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Wolfberry.h"
#include <fstream>
#include <cstdlib>
Organism* World::getCrature(int x, int y)
{	
	for (int i = 0; i < this->numberOfCreatures; i++)
	{
		if (((*organism[i]).getX() == x) && ((*organism[i]).getY() == y))
		{
			return organism[i];
		}
	}
	return nullptr;
}

void World::drawWorld()
{
	this->grid->refreshScreen();
	while(_getch())
	{			
		this->imput = _getch();
		if (imput == 's')
		{
			save();		
		}		
		if (imput == 'l')
		{
			load(); 
			continue;
		}		
		this->tour();
	}
}

void World::tour()
{
	Organism* duplicate = organism[0];
	std::sort(organism.begin(), organism.end(), Organism::compareTwoOrganismPointers);
	//
	//Reverse iteration (Most initative creatures are in the end).
	//
	for (int j = organism.size() - 1; j >= 0; j--)
	{
		if (duplicate == organism[j])
			continue;

		duplicate = organism[j];
		(*organism[j]).action();
		this->ClearDeadMonster();
		this->grid->refreshScreen();
	}
}

void World::save()
{
	std::ofstream myfile;
	std::string filename;
	std::cout << "Podaj nazwe pliku \n";
	std::cin >> filename;
	myfile.open(filename);
	this->serialize(myfile);
	myfile.close();
}

void World::load()
{
	std::ifstream ofile;
	std::string filename;
	std::cout << "Podaj nazwe pliku \n";
	std::cin >> filename;
	ofile.open(filename);
	this->deserialize(ofile);
	ofile.close();
}

void World::ClearDeadMonster()
{
	for (int i = 0; i < this->numberOfCreatures; i++)
	{
		if (!((*organism[i]).getIsAlive()))
		{			
			organism.erase(organism.begin() + i);
			numberOfCreatures--;
		}
	}
}

int* World::GetFreeSpot()
{
	bool isInitalized = false;
	int randX;
	int randY;
	while (!isInitalized)
	{
		randX = rand() % this->sizeX;
		randY = rand() % this->sizeY;
		//
		//If program find place where is a free spot, then while loop should stop and there 
		//will be place a creature
		//
		if (checkPosition(randX, randY) == 'o')
			isInitalized = true;
	}
	int tab[2];
	tab[0] = randX;
	tab[1] = randY;
	return tab;
}

std::vector<Organism*> World::getList()
{
	return organism;
}

int World::getImput()
{
	return this->imput;
}

void World::serialize(std::ostream & stream)
{
	stream << this->sizeX << " " <<  this->sizeY << " " << this->numberOfCreatures << " ";
	for (int i = 0; i < numberOfCreatures; i++)
	{
		if (organism[i]->getIsAlive())
		{
			stream << organism[i]->getName() << " " << organism[i]->getStrength() << " " << organism[i]->getX() << " " << organism[i]->getY() << " ";
		}		
	}
}

void World::deserialize(std::istream & stream)
{	
	this->organism.clear();
	std::string _sizeX;
	std::string _sizeY;
	std::string _numberOfCreatures;	
	stream >> _sizeX >> _sizeY >> _numberOfCreatures;
	this->sizeX = atoi(_sizeX.c_str());
	this->sizeY = atoi(_sizeY.c_str());
	this->setNumberoOfCreatures(0);
	this->grid->setNewSize(this->sizeX, this->sizeY);
	this->grid->clearScreen();
	this->grid->refreshScreen();
	for (int i = 0; i < atoi(_numberOfCreatures.c_str()); i++)
	{				
			std::string name;
			std::string strenght;
			std::string X;
			std::string Y;
			stream >> name >> strenght >> X >> Y;
			if (name == "Human")
			{
				this->addCreature(new Human(atoi(X.c_str()), atoi(Y.c_str()), this));				
			}
			else if (name == "Antelope")
			{
				this->addCreature(new Antelope(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "CyberSheep")
			{
				this->addCreature(new CyberSheep(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Fox")
			{
				this->addCreature(new Fox(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Grass")
			{
				this->addCreature(new Grass(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Guarana")
			{
				this->addCreature(new Guarana(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Sheep")
			{
				this->addCreature(new Sheep(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "SosnowskyBorsch")
			{
				this->addCreature(new SosnowskyBorsch(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "SowThistle")
			{
				this->addCreature(new SowThistle(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Turtle")
			{
				this->addCreature(new Turtle(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Wolf")
			{
				this->addCreature(new Wolf(atoi(X.c_str()), atoi(Y.c_str()), this));
			}
			else if (name == "Wolfberry")
			{
				this->addCreature(new Wolfberry(atoi(X.c_str()), atoi(Y.c_str()), this));
			}		
			this->organism[i]->setStrength(atoi(strenght.c_str()));
	}
}

void World::setNumberoOfCreatures(int number)
{
	this->numberOfCreatures = number;
}

int World::getNumberOfCreatures()
{
	return this->numberOfCreatures;
}

void World::addCreature(Organism* org)
{
	int* position = GetFreeSpot();
	organism.push_back(org);
	this->numberOfCreatures++;
	
}

char World::checkPosition(int x, int y)
{
	if ((x < 0) || (x > this->sizeX - 1) || (y < 0) || (y > this->sizeY - 1))
		return 'x';

	for (int i = 0; i < this->numberOfCreatures; i++)
	{		
		if (((*organism[i]).getX() == x) && ((*organism[i]).getY() == y))
		{			
			return 'm';
		}
	}
	return 'o';
}

Grid * World::getGrid()
{
	return this->grid;
}

World::World(int sizeX, int sizeY)
{
	this->numberOfCreatures = 0;
	grid = new Grid(sizeX, sizeY);
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

World::~World()
{

}

bool World::attackMonsterAtPosition(int x, int y, Organism* attacker)
{
	bool isDefended;
	for (int i = 0; i < this->numberOfCreatures; i++)
	{
		if (((*organism[i]).getX() == x) && ((*organism[i]).getY() == y))
		{
			std::string msg = attacker->getName() + " attack " + organism[i]->getName();
			this->getGrid()->setNewMessage(msg);
			isDefended = organism[i]->isPushBackAttack(attacker);			
			return !isDefended;
		}
	}
	return false;
}