#include "Creature.h"
#include "MainMenu.h"// If this is not here it causes loads of mistakes likely due to some form of cyclic include but I cant find the true reason

/*
Function to control the player taking damage (and healing)

@param int dmg: the amount of damage that will be taken
*/
void Creature::TakeDamage(int dmg)
{
	currentHealth = currentHealth - dmg;
	MainMenu::EnterLog(std::to_string(currentHealth) + " is the " + this->creatureName + "'s health");
}

/*
Used to generate the base parts of a creature

@param int creature: the creature type ID
*/
void Creature::GenerateCreature(int creature)
{
	creatureType = creature;//sets value out of switch as its common
	switch (creature)
	{
	case 0://Monk created
		maxHealth = 15;
		attackPower = 3;
		creatureName = "monk";
		break;
	case 1://Goblin created
		maxHealth = 10;
		attackPower = 2;
		creatureName = "Goblin" ;
		creatureDescription = "A small green creature with pointy ears and a club";
		break;
	case 2:// Kobold Created
		maxHealth = 3;
		attackPower = 1;
		creatureName = "Kobold";
		creatureDescription = "A small lizzard like creature that stands on all fours";
		break;
	case 3:// Orc Created
		maxHealth = 20;
		attackPower = 5;
		creatureName = "Orc";
		creatureDescription = "Large gray humanoids that are stronger and more durable then most others";
		break;
	case 4:// Slime Created
		maxHealth = 6;
		attackPower = 1;
		creatureName = "Slime";
		creatureDescription = "A gooey monster that errodes anything it touches";
		break;
	case 5:// Giant slime Created
		maxHealth = 20;
		attackPower = 1;
		creatureName = "Giant Slime";
		creatureDescription = "A large pile of goo that errodes everything it touches";
		break;
	case 6:// Dragon Created
		maxHealth = 200;
		attackPower = 10;
		creatureName = "Dragon";
		creatureDescription = "Its a dragon... good luck";
		break;
	case 7:// Wolf Created
		maxHealth = 5;
		attackPower = 2;
		creatureName = "Wolf";
		creatureDescription = "A medium size quadraped covered in fur";
		break;
	case 8:// Ogre Created
		maxHealth = 25;
		attackPower = 3;
		creatureName = "Ogre";
		creatureDescription = "Like a orc but a bit stupid";
		break;
	case 9:// Fish Created
		maxHealth = 1;
		attackPower = 0;
		creatureName = "Fish";
		creatureDescription = "Why is there a fish in a dungeon?";
		break;
	case 10:// Floating sword Created
		maxHealth = 5;
		attackPower = 5;
		creatureName = "Floating Sword";
		creatureDescription = "Well there is no ghost but a floating sword (its sharp)";
		break;
	default://Encase invalid input a goblin will be generated should not happen without coder error
		std::cout << "Invalid input for GenerateCreature function: Generating goblin of ID type 1 instead..." << std::endl;
		GenerateCreature(1);
		creatureType = 1;
		break;
	}
	currentHealth = maxHealth;
}

int Creature::getCurrentHealth()
{
	return currentHealth;
}

int Creature::getMaxHealth()
{
	return maxHealth;
}

int Creature::getAttackPower()
{
	return attackPower;
}

int Creature::getCreatureType()
{
	return creatureType;
}

void Creature::setCurrentHealth(int ch)
{
	currentHealth = ch;
}

void Creature::setMaxHealth(int mh)
{
	maxHealth = mh;
}

void Creature::setAttackPower(int ap)
{
	attackPower = ap;
}

void Creature::setCreatureType(int ct)
{
	creatureType = ct;
}

/*
Used to manage the creature attacking

@param Creature &target: The refrence of the creature it wants to hit

@return a boolean to say if it hit the target or not
*/
bool Creature::Attack(Creature &target)
{
	//Checks for 50% chance to hit
	int chance = rand() % 2;
	if (chance == 0) { MainMenu::EnterLog(creatureName + " failed to attack "); return false; }
	MainMenu::EnterLog(creatureName + " attacked " + target.getName());
	target.TakeDamage(attackPower);
	return true;
}

/*
Used to manage the creature defending

@return a boolean to say if it defended or not
*/
bool Creature::Deffend()
{
	//Checks for 50% chance to defend
	int chance = rand() % 2;
	if (chance == 0) { MainMenu::EnterLog(creatureName + " failed to deffended "); return false; }
	MainMenu::EnterLog(creatureName + " deffended ");
	if (currentHealth < maxHealth) { TakeDamage(-1); }
	return true;
}

void Creature::setName(std::string name)
{
	this->creatureName = name;
}

std::string Creature::getName()
{
	return creatureName;
}

void Creature::setDescription(std::string des)
{
	creatureDescription = des;
}

std::string Creature::getDescription()
{
	return creatureDescription;
}

Creature::Creature()
{
	//Generate a creature randomly from the creature table
	int type = (rand() % 10) + 1;
	GenerateCreature(type);
}

Creature::~Creature()
{
}
