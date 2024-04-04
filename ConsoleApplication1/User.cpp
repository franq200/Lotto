#include "User.h"
#include <iostream>

uint16_t User::GetUserNumber()
{
	uint16_t userNum = 0;
	std::cin >> userNum;
	return userNum;
}