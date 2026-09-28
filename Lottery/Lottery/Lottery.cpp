#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>

int main()
{
	int yourNums;
	int rounds = 6;
	int correctCounts = 0;
	bool validInput = false;
	std::string randomLotteryNums = "0";
	char nGames = 'y';


	int nums[50] = {
					  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
					  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
					  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
					  41, 42, 43, 44, 45, 46 ,47 ,48 ,49 ,50
	};

	std::cout << " ----- Welcome to the Lottery Game! -----\n"
		<< "You have to guess 6 numbers between 1 and 49!\n"
		<< "If you guess the right number, you will get a point.\n"
		<< "If you guess the wrong number, you will not get a point.\n"
		<< "Good luck!\n" << std::endl;


	std::srand(unsigned(std::time(nullptr)));

	std::cout << "Are you ready? (y/n)" << std::endl;

	std::cin >> nGames;

	while (nGames == 'y')
	{
		for (int i = 1; i <= 6; i++)
		{
			std::cout << "Please enter your number!" << std::endl;
			std::cin >> yourNums;

			int randomNums = rand() % 50 + 1;

			if (randomNums)
			{
				randomLotteryNums.push_back(randomNums);
			}

			std::cout << i << ". Lottery Number: " << randomNums << std::endl;

			if (yourNums < 1 || yourNums > 50) // Wie kann ich hier cin fail() benutzen?
			{
				std::cout << "Invalid number! Please enter a number between 1 and 50!\n" << std::endl;
				i--;
			}
			else
			{
				if (randomNums != yourNums)
				{
					std::cout << "You didnt get the right number! --- " << i << " out 6\n" << std::endl;
				}
				else if (randomNums == yourNums)
				{
					std::cout << "You got the right number! --- " << i << " out 6\n" << std::endl;

					correctCounts++;
				}
			}
		}
		std::cout << "you got " << correctCounts << " correct numbers!" << std::endl;
	}

	while (nGames == 'n')
	{
		std::cout << "Thank you for playing the Lottery Game! Goodbye!" << std::endl;
		return 0;
	}
}