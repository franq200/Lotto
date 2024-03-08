#pragma once
#include <vector>

using Numbers = std::vector<uint16_t>;

class IRandomEngine
{
public:
	virtual Numbers GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNuber, int maxNumber) = 0;
private:
};

