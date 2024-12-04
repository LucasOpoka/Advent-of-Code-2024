#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>


int main(void)
{
	std::ifstream inputFile("./input.txt");
	std::string line;
	std::regex ptrn("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
	int res = 0;

	while (std::getline(inputFile, line))
		for (std::sregex_iterator itr = std::sregex_iterator(line.begin(), line.end(), ptrn); itr != std::sregex_iterator(); itr++)
			res += std::stoi(itr->str(1)) * std::stoi(itr->str(2));

	std::cout << res << "\n";
	return 0;
}
