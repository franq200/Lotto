#pragma once
#include <vector>
#include "IRandomEngine.h"
#include "IUser.h"
#include <memory>

using Numbers = std::vector<uint16_t>;

struct Results
{
	Numbers correctNumbers = {};
	Numbers randomNumbers;
	Numbers playerNumbers;
};

class Lotto
{
public:
	Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine);
	Results GetResult();
private:
	Numbers m_randomNumbers;
	Numbers m_playerNumbers;
	std::unique_ptr<IRandomEngine> m_randomEngine;
	std::unique_ptr<IUser> m_userEngine;
};

