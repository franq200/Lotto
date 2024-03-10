#include "RandomEngine.h"
#include <cstdlib>

Numbers RandomEngine::GetUniqueRandomNumbers(int amountOfRandomNumbers, int minNumber, int maxNumber)
{
	Numbers randomNumbers;
	for (int i = 0; i < amountOfRandomNumbers; i++)
	{
		randomNumbers.push_back(rand() * maxNumber + minNumber);
		if (randomNumbers[i] < minNumber || randomNumbers[i] > maxNumber)
		{
			throw(std::exception("wylosowano liczby ze zlego zakresu"));
		}
	}
	return randomNumbers;
}
