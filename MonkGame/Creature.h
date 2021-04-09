#pragma once
#include <String>
class Creature
{
private:
	int currentHealth;
	int maxHealth;
	int attackPower;
	std::string creatureName;
	std::string creatureDescription;
	int creatureType; // 0 = Monk, 1 = Goblin;
public:
	void TakeDamage(int dmg);
	void GenerateCreature(int creature);
	int getCurrentHealth();
	int getMaxHealth();
	int getAttackPower();
	int getCreatureType();
	void setCurrentHealth(int ch);
	void setMaxHealth(int mh);
	void setAttackPower(int ap);
	void setCreatureType(int ct);
	bool Attack(Creature &target);
	bool Deffend();
	void setName(std::string name);
	std::string getName();
	void setDescription(std::string des);
	std::string getDescription();
	Creature();
	~Creature();
};

