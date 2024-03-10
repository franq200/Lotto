#pragma once
#include <vector>

using Numbers = std::vector<uint16_t>;

class IUser
{
public:
	virtual Numbers GetUserNumbers(int userNumbersAmount, int minNuber, int maxNumber) = 0;
private:
};

