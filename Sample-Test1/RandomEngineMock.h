#pragma once
#include <gmock/gmock.h>
#include "IRandomEngine.h"

class RandomEngineMock : public IRandomEngine
{
public:
	MOCK_METHOD(std::vector<uint16_t>, GetUniqueRandomNumbers, (int amountOfRandomNumbers, int minNuber, int maxNumber), (override));
};

