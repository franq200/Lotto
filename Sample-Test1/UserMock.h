#pragma once
#include <gmock/gmock.h>
#include "IUser.h"

class UserMock : public IUser
{
public:
	MOCK_METHOD(uint16_t, GetUserNumber, (), (override));
};

