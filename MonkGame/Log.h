#pragma once
#include <String>
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
class Log
{
public:
	static std::string startLog();
	static void logEnter(std::string fileName, std::string input);
};

