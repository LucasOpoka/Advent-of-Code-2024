#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

int main(void)
{
	std::string line;
	std::vector<int> vec;
	std::map<int, int> map;
	int n1, n2, res = 0;

	std::ifstream inputFile("./input.txt");

	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		ss >> n1 >> n2;
		vec.push_back(n1);
		map[n2] += 1;
	}

	for(int i = 0; i < vec.size(); i++)
    	res += vec[i] * map[vec[i]];

	std::cout << "Result: " << res << std::endl;
	
	return 0;
}
