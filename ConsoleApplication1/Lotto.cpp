#include "Lotto.h"
#include "IUser.h"
#include "IRandomEngine.h"
#include <iostream>
#include <algorithm>
#include <tuple>

Lotto::Lotto(std::unique_ptr<IRandomEngine> randomEngine, std::unique_ptr<IUser> userEngine):
	m_randomEngine(std::move(randomEngine)), m_userEngine(std::move(userEngine))
{
	InsertRandomNumbers();
	std::cout << "Liczby w zakresie od: " << 1 << " do: " << 49 << "\n"; //m_userEngine
	ReadUserNumbers();
}

Results Lotto::GetResult()
{
	Numbers correctNumbers;
	std::set_intersection(m_randomNumbers.begin(), m_randomNumbers.end(), m_playerNumbers.begin(), m_playerNumbers.end(), std::inserter(correctNumbers, correctNumbers.begin()));
	return Results{ correctNumbers, m_randomNumbers, m_playerNumbers };
}

void Lotto::ReadUserNumbers()
{
	for (int i = 0; i < 6; i++)
	{
		bool didSuccessfullyEmplaced = false;
		Numbers::iterator userNumIt;
		std::tie(userNumIt, didSuccessfullyEmplaced) = m_playerNumbers.emplace(m_userEngine->GetUserNumber());
		if (*userNumIt < 1 || *userNumIt > 49)
		{
			throw(std::exception("zly zakres liczb"));
		}
		if (!didSuccessfullyEmplaced)
		{
			//m_userEngine->OnNumberDuplicatedDetected();
			std::cout << "liczba sie powtarza, wpisz ponownie\n";
			i--;
		}
	}
}

void Lotto::InsertRandomNumbers()
{
	for (int i = 0; i < 6; i++)
	{
		bool didSuccessfullyEmplaced = false;
		Numbers::iterator randomNumIt;
		do
		{
			std::tie(randomNumIt, didSuccessfullyEmplaced) = m_randomNumbers.emplace(m_randomEngine->GetRandomNumber(1, 49));
		} while (!didSuccessfullyEmplaced);

		if (*randomNumIt < 1 || *randomNumIt > 49)
		{
			throw(std::exception("wylosowano liczby ze zlego zakresu"));
		}
	}
}
