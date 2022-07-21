#include <iostream>

int main()
{
	int magicSquare[9][9]{};
	int oddNumber, value{1};
	std::cout << "원하시는 홀수의 마방진을 보여드립니다." << std::endl;
	std::cin >> oddNumber;
	
	magicSquare[0][(oddNumber - 1) / 2] = value;

	while (value < oddNumber * oddNumber)
	{
		for (int i = 0; i < oddNumber; i++)
		{
			if (value == oddNumber * oddNumber)
			{
				break;
			}

			for (int j = 0; j < oddNumber; j++)
			{
				if (value == oddNumber * oddNumber)
				{
					break;
				}

				if (magicSquare[i][j] == value)
				{
					if (i == 0)
					{
						if (j == oddNumber - 1)
						{
							value++;
							magicSquare[i + 1][j] = value;
							continue;
						}
						value++;
						magicSquare[oddNumber - 1][j + 1] = value;
						continue;
					}

					if (j == oddNumber - 1)
					{
						if (magicSquare[i - 1][0] != 0)
						{
							value++;
							magicSquare[i + 1][j] = value;
							continue;
						}

						value++;
						magicSquare[i - 1][0] = value;
						continue;
					}

					if (magicSquare[i - 1][j + 1] != 0)
					{
						value++;
						magicSquare[i + 1][j] = value;
						continue;
					}
					value++;
					magicSquare[i - 1][j + 1] = value;
				}
			}
		}
	}

	for (int i = 0; i < oddNumber; i++)
	{
		for (int j = 0; j < oddNumber; j++)
		{
			if (magicSquare[i][j] == 0)
			{
				std::cout << " ";
			}

			if (magicSquare[i][j] > 0 && magicSquare[i][j] < 10)
			{
				std::cout << " " << magicSquare[i][j];
			}
			else
			{
				std::cout << magicSquare[i][j];
			}

		}
		std::cout << std::endl;
	}
}