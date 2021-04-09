#pragma once
#include "Creature.h"
#include <iostream>
class Room
{
private:
	bool isEmpty = false;
	std::string roomName = "Empty Room";
public:
	void SetIsEmpty(bool b);
	bool & GetIsEmpty();
	void SetRoomName(std::string rn);
	std::string GetRoomName();
	Room();
	Room(int type);
	~Room();
};

