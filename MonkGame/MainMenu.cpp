#include "MainMenu.h"

std::string MainMenu::logName;// local refrence to static logName value
/*
Function creates the dungeon starts it then destroys it at the end of the game
*/
void MainMenu::StartGame()
{
	Dungeon dungeon = Dungeon();// creates a new dungeon and saves it to a variable
	EnterLog("Dungeon generated");
	std::string playerName;
	std::string playerDescription;
	std::cout << "What would you like your character to be called: ";
	std::cin >> playerName;
	EnterLog("Player name set as: " + playerName);
	std::cout << std::endl << "Please give a short description of your character: ";
	std::cin >> playerDescription;
	EnterLog("Player description set as: " + playerDescription);
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	dungeon.StartDungeon(playerName, playerDescription);// starts the newly created dungeon
	dungeon.~Dungeon();// destroys the dungeon
}

/*
Generic function to generate the UI for each stage of the game

@param string UIName: the file name of the scene to be loaded
@param bool noDoor: bool to determin to print the no door in direction line with UI
@param bool invalidInput: bool to determin if the invalid input should be posted when displaying the UI
*/
void MainMenu::GenerateUI(std::string UIName, bool noDoor, bool invalidInput)
{
	system("cls");
	if (logName.size() < 1) {
		logName = Log::startLog();
		GenerateUI("MonkTitleScreen.txt", false, false);
	}
	std::ifstream file(UIName);
	std::string str;
	while (std::getline(file, str)) 
	{
		std::cout << str << std::endl;
	}
	MainMenu::EnterLog("Generated UI for the scene: " + UIName);
	if (noDoor) { std::cout << "                    There is no door in that direction" << std::endl; }
	if (invalidInput) { std::cout << "invalid input try again" << std::endl; }
	if (UIName == "MonkTitleScreen.txt") 
	{
		int input = 0;
		while (input < 1 || input > 3)
		{
			std::cin >> input;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			MainMenu::EnterLog("Player enters input on main menu with the input: " + input);
			EnterLog("Player entered input " + std::to_string(input));
			switch (input)
			{
			case 1:
				EnterLog("Game started a");
				MainMenu::StartGame();
				input = 0;
				break;
			case 2:
				EnterLog("Game quit");
				exit(0);
			default:
				MainMenu::EnterLog("Player's input was invalid error message 'Invalid input please try again..' sent");
				std::cout << "Invalid input please try again.." << std::endl;
				input = -1;
				break;
			}
		}
	}
	
	

}
/*
generic function to enter text into the log using the common inheritence of the MainMenu

@param string logEntry: the text that is wanted to be entered into the log
*/
void MainMenu::EnterLog(std::string logEntry)
{
	Log::logEnter(logName, logEntry);// Sends the log file name and the log text to the log enter function to save to the log file
}

