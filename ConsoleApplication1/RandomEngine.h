#pragma once
#include "IRandomEngine.h"

class RandomEngine : public IRandomEngine
{
public:
	std::vector<uint16_t> GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNuber, int maxNumber) override;
private:
};

