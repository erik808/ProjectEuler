#include <iostream>
#include <vector>

std::vector<size_t> digits(size_t number);

int main()
{
	std::vector<size_t> idf;
	std::vector<size_t> digs;
	size_t number = 0;
	idf.push_back(number);
	
	while (idf.size() <= 1000001)
	{
		number += 1;
		digs = digits(number);
		for (auto const &it: digs)
			idf.push_back(it);
	}

	size_t solution = idf[1] * idf[10] * idf[100] * idf[1000] * idf[10000]
                    		 * idf[100000] * idf[1000000];

	std::cout << solution << std::endl;
							 
	return 0;
}


std::vector<size_t> digits(size_t number)
{
	
	std::vector<size_t> digitarray;
	size_t order = 1;
	while (order <= number)
		order *= 10;
	order /= 10;
	while (order)
	{
		digitarray.push_back(number/order);
		number %= order;
		order /= 10;
	}
	return digitarray;
}
