#pragma once
#include "Room.h"
#include "Monk.h"
#include "BaseIncludes.h"

class Dungeon
{
private:
	Room dungeonRooms[5][5];
	bool noDoor = false;
	int playerPosX = 0, playerPosY = 0;
	Creature currentMonster;
	bool invalidInput = false;
	std::string combatUIText;
	char roomCons[5][5];
public:
	void StartDungeon(std::string playerName, std::string playerDescription);
	Dungeon();
	~Dungeon();
private:
	void TreasureRoomManager();
	int EmptyRoomManager(Room currentRoom);
	int MonsterRoomManager(Room currentRoom);
	void CombatUIGen(std::string text);
	std::string ExplorationUIGen();
};

