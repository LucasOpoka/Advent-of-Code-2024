#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>


int main(void)
{
	std::ifstream inputFile("./input.txt");
	std::string line;
	std::regex ptrn1("([0-9]{2})\\|([0-9]{2})");
	std::regex ptrn2("(\\d+)(,\\d+)+");
	int res = 0;
	std::map<int, std::vector<int>> map;

	while (std::getline(inputFile, line))
	{
		for (std::sregex_iterator itr = std::sregex_iterator(line.begin(), line.end(), ptrn1); itr != std::sregex_iterator(); itr++)
			map[std::stoi(itr->str(1))].push_back(std::stoi(itr->str(2)));
		
		if (std::regex_match(line, ptrn2))
		{
			std::stringstream ss(line);
			std::vector<int> vec;
			char sep;
			int tmp;
			bool cond = true;

			while (ss >> tmp)
			{
				vec.push_back(tmp);
				ss >> sep;
			}
		
			for (int i = 0; i < vec.size(); i++)
			{
				for (int j = 0; j < i; j++)
					cond = cond ? std::find(map[vec[i]].begin(), map[vec[i]].end(), vec[j]) == map[vec[i]].end() : cond;
			}

			if (cond)
				res += vec[vec.size() / 2];
		}
	}
	std::cout << res << "\n";
	return 0;
}
