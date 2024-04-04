#pragma once
#include <set>
#include <memory>

using Numbers = std::set<uint16_t>;

class IRandomEngine;
class IUser;

struct Results
{
	Numbers correctNumbers;
	Numbers randomNumbers;
	Numbers playerNumbers;
};

class Lotto
{
public:
	Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine);
	Results GetResult();
private:
	void ReadUserNumbers();
	void InsertRandomNumbers();
	Numbers m_randomNumbers;
	Numbers m_playerNumbers;
	std::unique_ptr<IRandomEngine> m_randomEngine;
	std::unique_ptr<IUser> m_userEngine;
};

