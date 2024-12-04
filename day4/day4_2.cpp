#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool theMeaningOfChristmas(std::vector<std::string> vec, int r, int c, int rmov, int cmov, int level, char const *s)
{
	if (level == 3)
		return true;
	if (0 <= r && r < vec.size() && 0 <= c && c < vec[0].size() && vec[r][c] == s[level])
		return theMeaningOfChristmas(vec, r + rmov, c + cmov, rmov, cmov, level + 1, s);
	else
		return 0;
}


int main(void)
{
	std::ifstream inputFile("./input.txt");
	std::string line;
	std::vector<std::string> vec;
	int res = 0;

	while (std::getline(inputFile, line))
		vec.push_back(line);

	for (int r = 0; r < vec.size(); r++)
	{
		for (int c = 0; c < vec[r].size(); c++)
		{
			res +=	(theMeaningOfChristmas(vec, r, c, -1,  1, 0, "MAS") +
					theMeaningOfChristmas(vec, r, c + 2, -1, -1, 0, "MAS") +
					theMeaningOfChristmas(vec, r, c, -1,  1, 0, "SAM") +
					theMeaningOfChristmas(vec, r, c + 2, -1, -1, 0, "SAM")) == 2;
		}
	}

	std::cout << res << "\n";
	return 0;
}
