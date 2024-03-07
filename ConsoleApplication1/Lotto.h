#pragma once
#include <vector>
#include "IRandomEngine.h"
#include "IUser.h"
#include <memory>

class Lotto
{
public:
	Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine);
private:
	std::vector<uint16_t> m_randomNumbers;
	std::vector<uint16_t> m_playerNumbers;
	std::unique_ptr<IRandomEngine> m_randomEngine;
	std::unique_ptr<IUser> m_userEngine;
};

