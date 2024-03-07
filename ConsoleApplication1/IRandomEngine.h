#pragma once
#include <vector>

class IRandomEngine
{
public:
	virtual std::vector<uint16_t> GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNuber, int maxNumber) = 0;
private:
};

