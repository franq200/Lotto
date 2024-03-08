#include "Lotto.h"

Lotto::Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine):
	m_randomEngine(std::move(randomEngine)), m_userEngine(std::move(userEngine))
{
	m_randomNumbers = m_randomEngine->GetUniqueRandomNumbers(6, 1, 49);
	m_playerNumbers = m_userEngine->GetUserNumbers(6);
}

Results Lotto::GetResult()
{
	return Results();
}
