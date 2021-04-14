#include "Dungeon.h"

Monk player;
/*
Base game function that controls the main core of the game

@param std::string playerName: The name of the player to be saved to the player
@param std::string playerDescription: The description of the player to save at the player
*/
void Dungeon::StartDungeon(std::string playerName, std::string playerDecription)
{
	player = Monk();
	//Spawns the treasure room into the dungeon
	int rand1 = (rand() % 4) + 1;
	int rand2 = (rand() % 4) + 1;
	dungeonRooms[rand1][rand2] = Room(2);
	//Sets all the map spaces to blank
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			roomCons[i][j] = ' ';
		}
	}
	
	//Sets up the first room and UI as well as all base values for the game
	invalidInput = false;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	player.setName(playerName);
	player.setDescription(playerDecription);
	currentMonster = Creature();
	currentMonster.GenerateCreature(0);
	Room currentRoom;
	dungeonRooms[playerPosX][playerPosY] = Room(0);
	MainMenu::GenerateUI(currentRoom.GetRoomName() + ".txt", noDoor, invalidInput);
	
	//Core game loop
	while (true)
	{
		int input = -1;
		currentRoom = dungeonRooms[playerPosX][playerPosY];
		while (input == -1)
		{
			MainMenu::GenerateUI(currentRoom.GetRoomName() + ".txt", noDoor, invalidInput);//Set up UI
			roomCons[playerPosX][playerPosY] = currentRoom.GetRoomName()[0];//Saves room type for the map
			std::cout << ExplorationUIGen() << std::endl;//Prints the map for the player to see
			if (currentRoom.GetRoomName() != "Monster Room") {
				std::cout << player.getName() << "'s current Health: " << player.getCurrentHealth() << std::endl;//Writes hp values
			}
			invalidInput = false;

			if (currentRoom.GetRoomName() == "Treasure Room" || currentRoom.GetRoomName() == "Player Dead")//Checks for game end
			{
				MainMenu::EnterLog("The map \n" + ExplorationUIGen());// saves map to the log
				TreasureRoomManager();
				MainMenu::GenerateUI("MonkTitleScreen.txt", false, false);
				return;
			}
			else if (currentRoom.GetRoomName() == "Monster Room")//Checks for fight room
			{
				if (currentMonster.getName() == "monk")//Spawns creature
				{
					combatUIText = "\n";
					currentMonster = Creature();
					std::cout << "A " << currentMonster.getName() << " appeared!!! its description reads " << currentMonster.getDescription();
				}
				std::cout << combatUIText << std::endl;//Spawns the combat history
				std::cout << player.getName() << " current Health: " << player.getCurrentHealth() << std::endl;//Writes hp values
				std::cout << currentMonster.getName() << "'s current Health: " << currentMonster.getCurrentHealth() << std::endl;//Writes hp values
				input = MonsterRoomManager(currentRoom);//Runs the combat turn setion
				//Generation of HP log to add to combat UI
				std::string tempText = "Turn end Player health is " + std::to_string(player.getCurrentHealth());
				tempText.append(" and the monsters health is " + std::to_string(currentMonster.getCurrentHealth()));
				tempText.append("\n");
				CombatUIGen(tempText);
				if (player.getCurrentHealth() <= 0) //Checks for dead
				{
					dungeonRooms[playerPosX][playerPosY].SetRoomName("Player Dead");//Uses room names to decide UI  so changes room of dead
					MainMenu::EnterLog("Combat endded with player death here is the log: \n" + combatUIText);
				}
			}
			else //Runs commands for any time the player can move
			{
				input = EmptyRoomManager(currentRoom);
			}
		}
	}
}

/*
Manages input for when the player is in a TreasureRoom or if they died
*/
void Dungeon::TreasureRoomManager() 
{
	int input = 0;
	std::cin >> input;
	MainMenu::EnterLog("Player entered input " + std::to_string(input));
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

/*
Manages input when the player is able to move
@param Room currentRoom: refrence to the current room for use in function
@return int: Returns the players input for the game loop
*/
int Dungeon::EmptyRoomManager(Room currentRoom)
{
	noDoor = false;// resets noDoor flag
	//Section sets up the UI and input
	int input = 0;
	std::cin >> input;
	MainMenu::EnterLog("Player entered input " + std::to_string(input));
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	switch (input)
	{
	case 1://Move Up
		if (playerPosY == 0) {//Check if they is not a room in requested direction
			noDoor = true;
			MainMenu::EnterLog("Player tried to move up but there was no door in that direction");
		}
		else if (&dungeonRooms[playerPosX][playerPosY - 1] != NULL) {//Checks if the room wanting to move to does exist (it should)
			playerPosY--;
		}
		else// In the case the room does not exist 
		{
			playerPosY--;
			dungeonRooms[playerPosX][playerPosY] = Room();
		}
		break;
	case 2:// Move Down
		if (playerPosY == 4) {//Check if they is not a room in requested direction
			noDoor = true;
			MainMenu::EnterLog("Player tried to move down but there was no door in that direction");
		}
		else if (&dungeonRooms[playerPosX][playerPosY + 1] != NULL) {// Check if the room wanting to move to does exist(it should)
			playerPosY++;
		}
		else// In the case the room does not exist
		{
			playerPosY++;
			dungeonRooms[playerPosX][playerPosY] = Room();
		}
		break;
	case 3:// Move Right
		if (playerPosX == 4) {// Checks if the room to move to does not exist
			noDoor = true;
			MainMenu::EnterLog("Player tried to move right but there was no door in that direction");
		}
		else if (&dungeonRooms[playerPosX + 1][playerPosY] != NULL) {// Check if the room wanting to move to does exist(it should)
			playerPosX++;
		}
		else// Encase the room to move to does not exist
		{
			playerPosX++;
			dungeonRooms[playerPosX][playerPosY] = Room();
		}
		break;
	case 4:// Move Left
		if (playerPosX == 0) { // Checks if the room to move to does not exist
			noDoor = true; 
			MainMenu::EnterLog("Player tried to move left but there was no door in that direction");
		}
		else if (&dungeonRooms[playerPosX - 1][playerPosY] != NULL) {// Check if the room wanting to move to does exist(it should)
			playerPosX--;
		}
		else// encase the room to move to does not exist
		{
			playerPosX--;
			dungeonRooms[playerPosX][playerPosY] = Room();
		}
		break;
	default:// Extra input and error collection
		if (input == 5 && currentRoom.GetRoomName() == "Empty Room")// Prayer manager
		{ 
			player.setCurrentHealth(player.getMaxHealth());
			std::cout << "Player Prayed" << std::endl;
		}
		else//error output 
		{
			invalidInput = true;
			input = -1;

		}
		break;
	}
	return input;
}

/*
Manages input when the player is in combat
@param Room currentRoom: refrence to the current room for use in function
@return int: Returns the players input for the game loop
*/
int Dungeon::MonsterRoomManager(Room currentRoom)
{

	//Function variable settup
	bool success;// Bool to check if player succeeded at a input
	int input = 0;
	std::cin >> input;
	MainMenu::EnterLog("Player entered input " + std::to_string(input));
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	switch (input)
	{
	case 1://Player wants to attack
		success = player.Attack(currentMonster);//sets the success value to wether or not the player hit using the attack function
		//System to add the result to the combat log.
		if (success) { CombatUIGen("Player attacked the monster and hit \n"); }
		else { CombatUIGen("Player missed when attacking the monster \n"); }
		break;
	case 2://Player wants to defend
		success = player.Deffend();// sets the success value to wether or not the players defence was succesfull
		//System to add result to combat log
		if (success) { CombatUIGen("Player succesfuly prepaired there defence \n"); }
		else { CombatUIGen("Player failed to prepair there defence \n"); }
		break;
	default://Players input was invalid
		invalidInput = true;
		input = -1;
		break;
	}
	if ((input == 1 || input == 2) && currentMonster.getCurrentHealth() > 0)//Checks if player input was valid and monster is not dead
	{
		//Monsters Turn
		int chance = rand() % 3 + 0;//Random to see if monster will defend or attack
		if (chance == 0)//Monster will defend
		{ 
			success = currentMonster.Deffend();//sets success to if monster sucesffuly defended whilst also running there defence
			//Adds to combat UI the result of there action
			if (success) { CombatUIGen("Monster succesfuly prepaired there defence \n"); }
			else { CombatUIGen("Monster failed to prepair there defence \n"); }
		}
		else {
			success = currentMonster.Attack(player);//sets success to if monster sucesffuly attacked whilst attacking the player
			//Adds to combat UI the result of there action
			if (success) { CombatUIGen("Monster attacked the player and hit \n"); }
			else { CombatUIGen("Monster missed when attacking the player \n"); }
		}
	}
	else if (currentMonster.getCurrentHealth() <= 0)//Is monster dead
	{
		MainMenu::EnterLog("Combat ended with following log: \n"+combatUIText);//Add combat log to main Log
		currentMonster.GenerateCreature(0);//Reset creature to monk (used as blank creature as only one monk should be in the game at a time)
		dungeonRooms[playerPosX][playerPosY].SetRoomName(currentRoom.GetRoomName().append("a"));// Changes to room name to mark the monster as defeated for UI generation
	}
	if (player.getCurrentHealth() > player.getMaxHealth()) { player.setCurrentHealth(player.getMaxHealth()); }// Makes sure player does not end combat with more HP then there max HP
	return input;
}

/*
Used to build a string that is used to display combat history

@param std::string text: Text wanted to be appended to the combat UI
*/
void Dungeon::CombatUIGen(std::string text)
{
	combatUIText.append(text);
}

/*
Used to display the Exploration UI that is the map

@return std::string: The returned value is the complete map based on what the player has seen
*/
std::string Dungeon::ExplorationUIGen()
{

	std::string temp = "";
	//Core loop to itterate across the Y axis
	for (int i = 0; i < 5; i++)
	{
		for (int n = 0; n < 27; n++) { temp.append(" "); }//Adds space to the row so it lines up better on the UI
		for (int j = 0; j < 5; j++)//Core loop to itterate across the X axis 
		{
			//Builds the box with the current known room locations
			temp.append("[");
			temp.push_back(roomCons[j][i]);
			temp.append("] ");
		}
		temp.append("\n");// Makes a new line at the end of each row
	}
	return temp;
}
	
Dungeon::Dungeon()
{
}

	Dungeon::~Dungeon()
	{
		player.~Monk();
	}

