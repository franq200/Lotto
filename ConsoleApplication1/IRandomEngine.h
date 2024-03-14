#pragma once
#include <set>

using Numbers = std::set<uint16_t>;

class IRandomEngine
{
public:
	virtual Numbers GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNumber, int maxNumber) = 0;
private:
};

