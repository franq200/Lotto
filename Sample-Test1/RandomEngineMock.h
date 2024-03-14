#pragma once
#include <gmock/gmock.h>
#include "IRandomEngine.h"

class RandomEngineMock : public IRandomEngine
{
public:
	MOCK_METHOD(Numbers, GetUniqueRandomNumbers, (int amountOfRandomNumbers, int minNuber, int maxNumber), (override));
};

