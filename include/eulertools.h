#ifndef EULERTOOLS_H
#define EULERTOOLS_H

#include <vector>
#include <iostream>
#include <string>

namespace Eulertools
{
	size_t order(size_t number);
	
	size_t vectorToDigit(std::vector<size_t> const &vec);

	std::vector<size_t> digitToVector(size_t number);

    void addVectors(std::vector<size_t> const &n1,
                    std::vector<size_t> const &n2,
                    std::vector<size_t> &dest);


	std::vector<size_t> convertToBinary(size_t num);

	std::vector<size_t> combinations(size_t size);

	std::string vec2str(std::vector<size_t> const &vec);
	
	void printVector(std::vector<size_t> const &vec);

	size_t factorial(size_t num);

    void reverseVector(std::vector<size_t> const &vec,
                      std::vector<size_t> &reverse);

    bool isPalindrome(std::vector<size_t> const &vec);
}

#endif
