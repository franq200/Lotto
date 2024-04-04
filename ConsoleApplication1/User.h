#pragma once
#include "IUser.h"

class User : public IUser
{
public:
	uint16_t GetUserNumber() override;
private:
};

