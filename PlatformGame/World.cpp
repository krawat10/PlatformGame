#pragma once 
#include <iostream>
#include <algorithm>
#include <random>
#include <conio.h>
#include <iostream>
#include "World.h"
#include "Organism.h"
#include "Grass.h"
#include "Human.h"
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
	for (size_t i = 0; i < 500; i++)
	{
		char imput = _getch();
		Organism* duplicate = nullptr;
		std::sort(organism.begin(), organism.end(), Organism::compareTwoOrganismPointers);
		//
		//Reverse iteration (Most initative creatures are in the end).
		//
		for (int j = numberOfCreatures-1; j >= 0 ; j--)
		{			
			if (organism[j] == duplicate)
				continue;
			if ((*organism[j]).getName() == "Human")
			{
				Human* human = (Human*)organism[j];
				human->action(imput);
			}
			else
			{
				(*organism[j]).action();
			}		
			duplicate = organism[j];
			this->ClearDeadMonster();
			this->grid->refreshScreen();
		}

	}
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
			isDefended = organism[i]->isPushBackAttack(attacker);
		}
	}
	return !isDefended;
}