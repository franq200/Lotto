#include "RandomEngine.h"
#include <cstdlib>

Numbers RandomEngine::GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNumber, int maxNumber)
{
	Numbers randomNumbers;
	for (int i = 0; i < amountOfRandomNumbers; i++)
	{
		bool isDuplicate = false;
		Numbers::iterator randomNumIt;
		do
		{
			std::tie(randomNumIt, isDuplicate) = randomNumbers.emplace(rand() * maxNumber + minNumber);
		} while (isDuplicate);
		
		if (*randomNumIt < minNumber || *randomNumIt > maxNumber)
		{
			throw(std::exception("wylosowano liczby ze zlego zakresu"));
		}
	}
	return randomNumbers;
}
