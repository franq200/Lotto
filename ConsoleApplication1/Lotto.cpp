#include "Lotto.h"

Lotto::Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine):
	m_randomEngine(std::move(randomEngine)), m_userEngine(std::move(userEngine))
{
	m_randomNumbers = m_randomEngine->GetUniqueRandomNumbers(6, 1, 49);
	m_playerNumbers = m_userEngine->GetUserNumbers(6, 1, 49);
}

Results Lotto::GetResult()
{
	Numbers correctNumbers;
	for (int i = 0; i < m_randomNumbers.size(); ++i)
	{
		if (m_randomNumbers[i] == m_playerNumbers[i])
		{
			correctNumbers.push_back(m_playerNumbers[i]);
		}
	}
	return Results{ correctNumbers, m_randomNumbers, m_playerNumbers };
}
