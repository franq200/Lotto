#pragma once
#include <gmock/gmock.h>
#include "IUser.h"

class UserMock : public IUser
{
public:
	MOCK_METHOD(Numbers, GetUserNumbers, (int userNumbersAmount, int minNuber, int maxNumber), (override));
};

