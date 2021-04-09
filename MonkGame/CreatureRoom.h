#pragma once
#include "Room.h"
#include "Creature.h"
class CreatureRoom :
	public Room
{
private:
	Creature monster;
	bool creatureDead;
public:
	void CreateMonster();
	void setCreatureDead(bool id);
	bool getCreatureDead();
	Creature getCreature();
};

