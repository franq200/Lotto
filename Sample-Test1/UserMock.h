#pragma once
#include <gmock/gmock.h>
#include "IUser.h"

class UserMock : public IUser
{
public:
	MOCK_METHOD(std::vector<uint16_t>, GetUserNumbers, (), (override));
};

