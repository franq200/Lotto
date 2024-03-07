#pragma once
#include "IUser.h"

class User : public IUser
{
public:
	std::vector<uint16_t> GetUserNumbers() override;
private:
};

