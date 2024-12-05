#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

bool sub_f(std::vector<int> vec, int i, int j, int asc, int dsc, bool dumper)
{
	bool cond1, cond2;

	if (j == vec.size()) 
		return true;	// terminating condition
	if (i < 0)
		return sub_f(vec, j, j + 1, asc, dsc, dumper);	// removing first element in vector case

	int diff = std::abs(vec[j] - vec[i]);
	cond1 = 1 <= diff && diff <= 3;
	int n_asc = asc + (vec[i] < vec[j]);
	int n_dsc = dsc + (vec[i] > vec[j]);
	cond2 = (n_asc && !n_dsc) || (!n_asc && n_dsc);
	
	if (cond1 && cond2)
		return sub_f(vec, j, j + 1, n_asc, n_dsc, dumper);	// valid pair case
	else if (dumper)
		return sub_f(vec, i - 1, j, std::max(asc - 1, 0), std::max(dsc - 1, 0), false)	// removing first in pair
		|| sub_f(vec, i, j + 1, asc, dsc, false)										// removing second in pair
		|| sub_f(vec, i, j, std::max(asc - 1, 0), std::max(dsc - 1, 0), false);			// removing value before pair
	return false;
}

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
		
		while (ss >> tmp)
			vec.push_back(tmp);

		int sub_res = sub_f(vec, 0, 1, 0, 0, true);
		res += sub_res;
	}
	std::cout << "Result: " << res << std::endl;
	return 0;
}
