#include "RandomEngine.h"
#include <cstdlib>
#include <ctime>

RandomEngine::RandomEngine()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

uint16_t RandomEngine::GetRandomNumber(int min, int max)
{
	return rand() * max + min;
}

/*
Numbers randomNumbers;
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
*/
