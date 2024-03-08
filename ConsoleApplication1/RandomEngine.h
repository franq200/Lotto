#pragma once
#include "IRandomEngine.h"

class RandomEngine : public IRandomEngine
{
public:
	Numbers GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNuber, int maxNumber) override;
private:
};

