#pragma once

#include <fstream>
#include "Dungeon.h"
#include"Log.h"
#include "BaseIncludes.h"

class MainMenu
{
private:
	static void StartGame();
public:
	static std::string logName;
	static void GenerateUI(std::string UIName, bool noDoor, bool invalidInput);
	static void EnterLog(std::string logEntry);
};

