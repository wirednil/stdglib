#include "toha.h"

#include <stdio.h>
#include <string>
#include <sstream>

/**
 * @brief Initializes the seed for the random number generator.
 */
bool initSeed = false;

const int TopeGuid = 27;

/**
 * @brief Generates a random character.
 * @return A string containing a random character.
 */
std::string getRandomChar(void);

/**
 * @brief Generates a random number.
 * @return A string containing a random number.
 */
std::string getRandomNum(void);

/**
 * @brief Generates a random letter.
 * @return A string containing a random letter.
 */
std::string getRandomLetter(void);

std::string toha::getGloballyUniqueIdentifier(void) 
{
    std::string GUID = "";
	for(int i=0;i<TopeGuid; ++i) {
		GUID += (i==8 || i==13 || i==18) ? "-" : getRandomChar();
	}
	return GUID;
}

std::string getRandomChar(void) 
{
	if (!initSeed) {
		srand(time(0));
		initSeed = true;
	}
	return (rand() % 2) ? getRandomNum() : getRandomLetter();
}

std::string getRandomNum(void)
{
	std::stringstream num;
	num << rand()% 10;
	return num.str();
}

std::string getRandomLetter(void)
{
	std::string chr;
	chr = 'a'+ ( rand() % ('z' - 'a') );
	return chr;
}