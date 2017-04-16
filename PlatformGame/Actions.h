#pragma once
#include "Action.h"
class NormalPlantAction:public Action
{
public:
	NormalPlantAction();
	~NormalPlantAction();
	void action(Organism* org)
	{
		World* world = org->getWorld();
		
	}

};
