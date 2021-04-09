#include "Room.h"

void Room::SetIsEmpty(bool b)
{
	isEmpty = b;
}

bool & Room::GetIsEmpty()
{
	return isEmpty;
}

void Room::SetRoomName(std::string rn)
{
	roomName = rn;
}

std::string Room::GetRoomName()
{
	return roomName;
}

/*
Room constructor to create a random room
*/
Room::Room()
{
	int type = rand() % 2 + 0;
	switch (type)
	{
	case 0:
		isEmpty = true;
		roomName = "Empty Room";
		break;
	case 1:
		isEmpty = false;
		roomName = "Monster Room";
		break;
	default:
		std::cout << "New room creation error 0, Invalid Type" << std::endl;
		break;
	}
}
/*
Room constructor for creating of a specific type of room

@param int type: The intiger/ID of the room type to be created.
*/
Room::Room(int type)
{
	switch (type)
	{
	case 0:
		isEmpty = true;
		roomName = "Empty Room";
		break;
	case 1:
		this->isEmpty = false;
		roomName = "Monster Room";
		break;
	case 2:
		this->isEmpty = true;
		roomName = "Treasure Room";
		break;
	default:
		std::cout << "New room creation error 0, Invalid Type" << std::endl;
		break;
	}
}
/*
room deconstructor
*/
Room::~Room()
{
}
