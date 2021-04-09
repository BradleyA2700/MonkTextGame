#include "Monk.h"
/*
Monks pray ability to heal the player
*/
void Monk::Pray()
{
	MainMenu::EnterLog("Player prayed");
	setCurrentHealth(getMaxHealth());
}
/*
Monk constructor
*/
Monk::Monk()
{
	GenerateCreature(0);
}
/*
Monk deconstructor
*/
Monk::~Monk()
{
}
