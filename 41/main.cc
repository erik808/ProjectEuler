#include <iostream>
#include <vector>
#include <array>
#include "../primes/primes.h"

using namespace std;

vector<size_t> sieve(size_t max);
bool           isPandigital(size_t number);
vector<size_t> digitToVector(size_t number);

template<typename T>
size_t         arrayToDigit(T &array);

vector<size_t> createPandigitals();
void           next(size_t position);


size_t const pandigitalSize = 7;
array<size_t, pandigitalSize> pandigital;
vector<size_t>  pandigitalStorage;


int main()
{
	Primes primes(1000);
	vector<size_t> list;
	primes.exportPrimes(list);
	cout << list.size() << '\n';
	pandigital.fill(0);
	createPandigitals();

	std::cout << "pandigitalStorage.size(): "
			  <<  pandigitalStorage.size() << '\n';
	
	for (size_t idx = pandigitalStorage.size(); idx--;)
	{
		bool primeFlag = false;
		for (auto const &prime: list)
			if (pandigitalStorage[idx] % prime == 0)
			{
				primeFlag = false;
				break;
			}
			else
				primeFlag = true;
		if (primeFlag)
		{
			cout << pandigitalStorage[idx] << '\n';
			break;
		}
	}
}

vector<size_t> createPandigitals()
{
	for (size_t i = 1; i <= pandigitalSize; ++i)
	{
		size_t pos = 0;
		pandigital[pos] = i;
		next(pos + 1);
	}
}
	
void next(size_t position)
{
	if (position == pandigitalSize)
		return;

	bool skipFlag = false;
	for (size_t i = 1; i <= pandigitalSize; ++i)
	{
		for (size_t idx = 0; idx != position; ++idx)
			if (pandigital[idx] == i)
				skipFlag = true;

		if (skipFlag)
		{
			skipFlag = false;
			continue;
		}
		pandigital[position] = i;

		if (position == pandigitalSize - 1)
		{
			pandigitalStorage.push_back(arrayToDigit(pandigital));
			continue;
		}
		next(position + 1);
	}	
	return;
}

bool isPandigital(size_t number)
{
	vector<size_t> array = digitToVector(number);
	vector<size_t> dum;
	dum.insert(dum.begin(), array.size()+1, 0);
	for (auto const &a: array)
	{
		dum[a]++;
		if (dum[a] > 1)
			return false;
	}
 
	for (size_t i = 1; i != dum.size(); ++i)
		if (dum[i] != 1)
			return false;
	return true;
}

template<typename T>
size_t         arrayToDigit(T &array)
{
	size_t digit = 0;
	size_t order = 1;
	for (size_t it = 0; it != array.size() - 1; ++it)
		order *= 10;

	for (auto const &it: array)
	{
		digit += it * order;
		order /= 10;
	}

	return digit;
}

vector<size_t> digitToVector(size_t number)
{	
	vector<size_t> digitarray;
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
