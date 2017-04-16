#pragma once
//
//Strategy design pattern which implement unique actions to unique object
//
#include "Organism.h"
class Action
{
public:
	Action() {};
	~Action() {};
	virtual void action(Organism* org) =0;
};
