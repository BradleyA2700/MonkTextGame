#include "Log.h"
#pragma warning(disable : 4996)


/*
Function to generate the file for the log and generates its name based on the time of creation

@return string: the name of the log to be saved for future use
*/
std::string Log::startLog()
{
	// 3 lines save the current date and time and uses Ctime to change it into a string format
	auto tempTime = std::chrono::system_clock::now();
	std::time_t timeDate = std::chrono::system_clock::to_time_t(tempTime);
	std::string fileName = std::ctime(&timeDate);


	size_t startingPosition = 0; // sets a base counter
	while ((startingPosition = fileName.find(":", startingPosition)) != std::string::npos)// Loop changes the ':' to '_' so the name meets windows file name reqiurements
	{
		fileName.replace(startingPosition, 1, "_");
		startingPosition++;
	}

	fileName.pop_back();// Removes the last character from the file name this is a new line modifier
	fileName.append(".txt");// Adds the .txt suffix to file so it will be saved as a readable text doccument
	std::ofstream file(fileName);// creates a file names by the string saved in fileName
	file << "Started log at " << std::ctime(&timeDate) << std::endl;// Enters into the log the instance of creation with date time
	file.close();// closes the file
	return fileName;// returns the name of the file
}

/*
Function used to enter text into the log

@param string fileName: saved file name of the log for the session
@param string input: input to be saved into the log
*/

void Log::logEnter(std::string fileName, std::string input)
{
	// next 3 lines save the current date time as a string for use in adding to the log
	auto tempTime = std::chrono::system_clock::now();
	std::time_t timeDate = std::chrono::system_clock::to_time_t(tempTime);
	std::string stringTime = std::ctime(&timeDate);
	
	std::ofstream file;// creates a file to save the file in
	file.open(fileName,std::ios::app);// opens the file to the file variable in append mode
	file << stringTime << " " << input << std::endl;// saves the date time followed by desired input into the log
	file.close();// closes the file
}
