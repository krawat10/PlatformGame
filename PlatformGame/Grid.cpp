#pragma once
#include <stdlib.h>
#include "Grid.h"
#include <iostream>

using namespace std;

bool Grid::isInstance = false;

Grid::Grid(int sizeX, int sizeY)
{
	if (!isInstance)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->screen = (char**)malloc(sizeY * sizeof(char*));
		for (int i = 0; i < sizeY; i++)
		{
			this->screen[i] = (char*)malloc(sizeX * sizeof(char));
		}
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				screen[i][j] = '.';				
			}			
		}
		refreshScreen();
		isInstance = true;
		string word = "*************";
		messages.push_back(word);
		messages.push_back(word);
		messages.push_back(word);
	}
	//
	//Throw exception when we try to create next instance of Grid class.
	//
	else
	{
		throw std::runtime_error("Class called Grid have already an instance.");
	}
}

Grid::~Grid()
{
}

void Grid::refreshScreen()
{
	system("cls");

	for (int j = 0; j < this->sizeX+2; j++)
		cout << '_';
	cout << endl;
	for (int i = 0; i < this->sizeY; i++)
	{
		cout << '|';
		for (int j = 0; j < this->sizeX; j++)
		{			
			cout << screen[i][j];
		}
		cout << '|';
		cout << endl;
	}
	for (int j = 0; j < this->sizeX+2; j++)
		cout << '~';
	cout << endl;
	for (int i = 0; i < messages.size(); i++)
	{
		cout << messages[i] << endl;
	}
}

void Grid::clearScreen()
{
	for (int i = 0; i < this->sizeY; i++)
	{		
		for (int j = 0; j < this->sizeX; j++)
		{
			screen[i][j] = '.';
		}	
	}
	string word = "*************";
	for (int i = 0; i < 3; i++)
	{
		messages[i] = word;
	}
}

void Grid::setNewSize(int x, int y)
{
	this->sizeX = x;
	this->sizeY = y;
}

void Grid::setObject(int x, int y)
{
	screen[y][x] = 'x';
	refreshScreen();
}

void Grid::setObject(int x, int y, char symbol)
{
	screen[y][x] = symbol;
	refreshScreen();
}

void Grid::deleteObject(int x, int y)
{
	screen[y][x] = '.';
	refreshScreen();
}

void Grid::setNewMessage(std::string message)
{
	messages[2] = messages[1];
	messages[1] = messages[0];
	messages[0] = message;
	refreshScreen();
}

