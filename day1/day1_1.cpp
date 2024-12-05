#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::string line;
	std::vector<int> vecA, vecB;
	int n1, n2, res = 0;

	std::ifstream inputFile("./input.txt");

	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		ss >> n1 >> n2;
		vecA.push_back(n1);
		vecB.push_back(n2);
	}
	std::sort(vecA.begin(), vecA.end());
	std::sort(vecB.begin(), vecB.end());

	for(int i = 0; i < vecA.size(); i++)
    	res += std::abs(vecA[i] - vecB[i]);

	std::cout << "Result: " << res << std::endl;
	
	return 0;
}
