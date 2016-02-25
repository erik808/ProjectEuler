#include "eulertools.h" 

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
size_t Eulertools::vectorToDigit(std::vector<size_t> vec)
{
	size_t result = 0;
	size_t base = 1;
	
	for (std::vector<size_t>::iterator itr = vec.end()-1;
		 itr >= vec.begin(); --itr)
	{
		result += *itr * base;
		base *= 10;
	}

	return result;		
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
void Eulertools::printVector(std::vector<size_t> &vec)
{
	for (auto const &v: vec)
		std::cout << v << " ";
	std::cout << std::endl;
}
