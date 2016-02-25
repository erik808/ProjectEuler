#ifndef EULERTOOLS_H
#define EULERTOOLS_H

#include <vector>
#include <iostream>

namespace Eulertools
{
	size_t order(size_t number);
	std::vector<size_t>  digitToVector(size_t number);
	std::vector<size_t> convertToBinary(size_t num);
	size_t vectorToDigit(std::vector<size_t> vec);
	std::vector<size_t> combinations(size_t size);
	void printVector(std::vector<size_t> &vec);
}

#endif
