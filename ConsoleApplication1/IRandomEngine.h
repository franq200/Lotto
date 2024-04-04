#pragma once
#include <set>

class IRandomEngine
{
public:
	virtual ~IRandomEngine() = default;
	virtual uint16_t GetRandomNumber(int min, int max) = 0;
private:
};
