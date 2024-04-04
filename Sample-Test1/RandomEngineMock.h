#pragma once
#include <gmock/gmock.h>
#include "IRandomEngine.h"

class RandomEngineMock : public IRandomEngine
{
public:
	MOCK_METHOD(uint16_t, GetRandomNumber, (int min, int max), (override));
};

