#include "Lotto.h"
#include "IUser.h"
#include "IRandomEngine.h"
#include <iostream>
#include <algorithm>

Lotto::Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine):
	m_randomEngine(std::move(randomEngine)), m_userEngine(std::move(userEngine))
{
	try
	{
		m_randomNumbers = m_randomEngine->GetUniqueRandomNumbers(6, 1, 49);
		m_playerNumbers = m_userEngine->GetUserNumbers(6, 1, 49);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}

Results Lotto::GetResult()
{
	Numbers correctNumbers;
	std::set_intersection(m_randomNumbers.begin(), m_randomNumbers.end(), m_playerNumbers.begin(), m_playerNumbers.end(), std::inserter(correctNumbers, correctNumbers.begin()));
	return Results{ correctNumbers, m_randomNumbers, m_playerNumbers };
}
