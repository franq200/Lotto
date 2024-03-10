#pragma once
#include "IUser.h"

class User : public IUser
{
public:
	Numbers GetUserNumbers(int userNumbersAmount, int minNuber, int maxNumber) override;
private:
};

