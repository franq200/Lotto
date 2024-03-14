#pragma once
#include <set>

using Numbers = std::set<uint16_t>;

class IUser
{
public:
	virtual Numbers GetUserNumbers(int userNumbersAmount, int minNuber, int maxNumber) = 0;
private:
};

