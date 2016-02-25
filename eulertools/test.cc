#include "eulertools.h"

int main()
{
	std::vector<size_t> vec = {1, 0, 2, 2, 2, 0};
	size_t num = Eulertools::vectorToDigit(vec);
	std::cout << num << '\n';

	std::vector<size_t> bin1 = Eulertools::convertToBinary(7);
	Eulertools::printVector(bin1);
	std::vector<size_t> bin2 = Eulertools::convertToBinary(255);
	Eulertools::printVector(bin2);

	std::cout << Eulertools::factorial(9) << std::endl;
	
	return 0;
}
