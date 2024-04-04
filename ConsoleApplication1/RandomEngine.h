#pragma once
#include "IRandomEngine.h"

class RandomEngine : public IRandomEngine
{
public:
	RandomEngine();
	~RandomEngine() override = default;
	uint16_t GetRandomNumber(int min, int max) override;
private:
};

