#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::string line;
	std::vector<int> vec;
	int res = 0, tmp;

	std::ifstream inputFile("./input.txt");

	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::vector<int> vec;
		bool sub_res = true;
		int sign = 0;
		
		while (ss >> tmp)
			vec.push_back(tmp);

		std::adjacent_find(vec.begin(), vec.end(),
			[&](int a, int b)
			{
				int diff = b - a;
				if (!sign)
					sign = (diff < 0) ? -1 : 1;
				diff *= sign;
				if (sub_res)
					sub_res = (1 <= diff && diff <= 3);
				return 0;
			}
		);

		res += sub_res;
	}
	std::cout << "Result: " << res << std::endl;
	return 0;
}
