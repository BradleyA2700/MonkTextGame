// MonkGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MainMenu.h"
int main()
{
	srand((unsigned int)time(NULL));//sets the random seed
	MainMenu::GenerateUI("MonkTitleScreen.txt", false, false);//starts the game by generating the UIm 
}
/*
How to edit this code

Want to add more creatures:

Go to the Creature.cpp::GenerateCreature function and add increase the value being placed into the Rand()
by how how many creatures you want to add. Then add to the switch below your new creature following the design
of the previous creatures this automaticaly adds it to the pool for when a monster room is entered.

Add something to the log:

If the class has a inclusion of MainMenu.h at some point in its includes you can use the MainMenu::EnterLog(text)
and add the text that you would like to have entered into the log the date time will be done automaticaly from the code

Add a error message:

During any function where the game needs to send a UI generation request to the main menu there should be a function 
that replaces the invalidInput boolean in the UIGeneration function set this to true if you want a error message to pop up

Add a decorative room:

As there is currently no way to implement a room with functionality easily simply create a new Text document and create its UI
save it in the source folder and head to the Room.cpp file in the standard constructor you can then increment the number
going into Rand() by 1 and add the new room to the switch below (Make sure its room name matches the name of the text file
created not including the .txt at the end) this will then spawn in a new none functional room into the game.
*/