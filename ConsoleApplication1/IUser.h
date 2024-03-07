#pragma once
#include <vector>

class IUser
{
public:
	virtual std::vector<uint16_t> GetUserNumbers() = 0;
private:
};

