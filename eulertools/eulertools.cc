#include "eulertools.h"
#include <sstream>

//------------------------------------------------------------------
size_t Eulertools::order(size_t number)
{
	size_t order = 1;
	while (order <= number)
		order *= 10;
	order /= 10;
	return order;
}

//------------------------------------------------------------------
std::vector<size_t> Eulertools::digitToVector(size_t number)
{	
	std::vector<size_t> digitarray;
	size_t ord = order(number);

	while (ord)
	{
		digitarray.push_back(number/ord);
		number %= ord;
		ord /= 10;
	}
	return digitarray;
}

//------------------------------------------------------------------
size_t Eulertools::vectorToDigit(std::vector<size_t> const &vec)
{
	size_t result = 0;
	size_t base = 1;
	
	for (std::vector<size_t>::const_iterator itr = vec.end()-1;
		 itr >= vec.begin(); --itr)
	{
		result += *itr * base;
		base *= 10;
	}

	return result;		
}

//------------------------------------------------------------------
void Eulertools::addVectors(std::vector<size_t> const &n1,
                            std::vector<size_t> const &n2,
                            std::vector<size_t> &dest)
{

	size_t size1 = n1.size();
	size_t size2 = n2.size();
	
    std::vector<size_t> const *max = (size1 > size2) ? &n1 : &n2;
    std::vector<size_t> const *min = (size1 > size2) ? &n2 : &n1;

	dest = std::vector<size_t>(*max);
	
    std::vector<size_t>::const_reverse_iterator ritMax  = max->rbegin();
    std::vector<size_t>::const_reverse_iterator ritMin  = min->rbegin();
    std::vector<size_t>::reverse_iterator ritDest = dest.rbegin();

	for (; ritMax != max->rend(); ++ritMax)
	{
		if (ritMin < min->rend())		
			*ritDest = *ritDest + *ritMin;

		if (*ritDest > 9)
		{
			*ritDest %= 10;
			if ((ritDest + 1) != dest.rend())
				*(ritDest+1) += 1;
			else
				dest.insert(dest.begin(), 1);
		}
				
		++ritMin;
		++ritDest;
	}
}

//------------------------------------------------------------------
std::vector<size_t> Eulertools::convertToBinary(size_t num)
{
	std::vector<size_t> binary;
	while (num)
	{
		if (num % 2)
			binary.push_back(1);
		else
			binary.push_back(0);

		num /= 2;
	}

	std::vector<size_t> result;
	for (std::vector<size_t>::iterator itr =  binary.end() - 1;
		 itr >= binary.begin(); --itr)
	{
		result.push_back(*itr);
	}

	return result;	
}

//------------------------------------------------------------------
// Creates a vector of size_t's containing all the possible combinations
// of entries in a vector of size <size>. Use digitToVector to convert
// an entry to an indexing vector.
std::vector<size_t> Eulertools::combinations(size_t size)
{
	size_t largest = 1;
	for (size_t i = 0; i != size; ++i)
	{
		largest *= 2;
	}
	largest -= 1;
	
	size_t bin;
	std::vector<size_t> result;
	for (size_t i = 1; i <= largest; ++i)
	{
		bin = Eulertools::vectorToDigit(Eulertools::convertToBinary(i));
		result.push_back(bin);
	}	
	return result;
}

//------------------------------------------------------------------
std::string Eulertools::vec2str(std::vector<size_t> const &vec)
{
	std::stringstream strstream;
	for (auto &v: vec) strstream << v;
	return strstream.str();
}

//------------------------------------------------------------------
void Eulertools::printVector(std::vector<size_t> const &vec)
{
	for (auto const &v: vec)
		std::cout << v << " ";
	std::cout << std::endl;
}

//------------------------------------------------------------------
size_t Eulertools::factorial(size_t num)
{
	size_t result = num;
	for (size_t i = num-1; i != 0; --i)
		result *= i;
	return result;
}

//------------------------------------------------------------------
void Eulertools::reverseVector(std::vector<size_t> const &vec,
                              std::vector<size_t> &reverse)
{
    reverse.clear();
    std::vector<size_t>::const_reverse_iterator ritvec = vec.rbegin();
    for (; ritvec != vec.rend(); ++ ritvec)
        reverse.push_back(*ritvec);
}

//------------------------------------------------------------------
bool Eulertools::isPalindrome(std::vector<size_t> const &vec)
{
    std::vector<size_t>::const_reverse_iterator rit = vec.rbegin();
    std::vector<size_t>::const_iterator it = vec.begin();

    for (; it != vec.end(); ++it, ++rit)
    {
        if (*it != *rit)
            return false;
    }
    return true;        
}
