#include "User.h"
#include <iostream>

Numbers User::GetUserNumbers(int userNumbersAmount, int minNumber, int maxNumber)
{
	Numbers userNumbers;
	std::cout << "Liczby w zakresie od " << minNumber << " do " << maxNumber << "\n";
	for (int i = 0; i < userNumbersAmount; i++)
	{
		std::cout << "\nPodaj " << i << " liczbe: ";
		uint16_t number = 0;
		std::cin >> number;
		if (number < minNumber || number > maxNumber)
		{
			throw(std::exception("zly zakres liczb"));
		}
		auto [randomNumIt, isDuplicate] = userNumbers.emplace(number);
		if (isDuplicate)
		{
			std::cout << "liczba sie powtarza, wpisz ponownie\n";
			i--;
		}
	}
	return userNumbers;
}
