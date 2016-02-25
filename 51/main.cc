#include "primes.h"
#include "eulertools.h"
#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX(x,y) x > y ? x : y

using namespace std;
using namespace Eulertools;

std::vector<size_t> combinations(size_t lower, size_t upper);
bool isCandidate(vector<size_t> &prime, vector<size_t> &comb);

int main()
{
	size_t lower_lim = 1;
	size_t upper_lim = 999999;
	vector<size_t> combs = combinations(lower_lim, upper_lim);

	for (auto &c: combs)
		cout << c << " | ";
	cout << std::endl;

	std::cout << " building primes ... " << std::endl;
	Primes P(upper_lim);
	std::cout << " building primes ... done" << std::endl;
	vector<size_t> primes = P.getPrimes();
	vector<size_t> prime_vec, comb_vec;
	for (auto &prime: primes)
	{
		prime_vec = Eulertools::digitToVector(prime);
		for (auto &comb: combs)
		{
			comb_vec = Eulertools::digitToVector(comb);
			if (comb_vec.size() > prime_vec.size())
				break;
			
			if (isCandidate(prime_vec, comb_vec))
			{
				size_t counter = 0;
				size_t test;
				for (size_t i = 0; i != 10; ++i)
				{
					test = prime + i*comb;
					if (order(test) != order(prime))
						break;
					
					if (P.inPrimes(test))
						counter++;
				}
				if (counter >= 8)
				{
					std::cout << comb << " " << counter << "\n-------\n";
					for (size_t i = 0; i != 10; ++i)
					{
						test = prime + i*comb;
						if (order(test) != order(prime))
							break;

						std::cout << test << " "
								  << P.inPrimes(test) << '\n';
					}
					return 0;
				}				
			}
		}
	}
	return 1;
}

bool isCandidate(vector<size_t> &prime, vector<size_t> &comb)
{
	size_t ps = prime.size();
	size_t cs = comb.size();

	if (cs > ps)
	{
		std::cout << " cs > ps returning\n";
		return false;
	}				
	
	size_t sdif = ps - cs;	
	comb.insert(comb.begin(), sdif, 0);

 	bool result = false;
	bool initial = true;
	size_t value = 0;
	
	for (size_t idx = 0; idx != prime.size(); ++idx)
	{
		if (initial && comb[idx] && (prime[idx] <= 1))
		{
			initial = false;
			value = prime[idx];
		}
		
		if (comb[idx] && (prime[idx] == value))
			result = true;
		else if (comb[idx] && (prime[idx] != value))
		{
			result = false;
			break;
		}
		
	}
	return result;
}

std::vector<size_t> combinations(size_t lower, size_t upper)
{
	vector<size_t> result;
	vector<size_t> upvec = Eulertools::digitToVector(upper);
	size_t size = upvec.size();
	std::cout << " size = " << size << '\n';
	
	size_t largest = 1;
	for (size_t i = 0; i != size; ++i)
	{
		 largest *= 2;
	}
	largest -= 1;
	std::cout << " largest = " << largest << '\n';
	
	std::vector<size_t> binary = Eulertools::digitToVector(largest);

	size_t bin;
	for (size_t i = 1; i <= largest; ++i)
	{
		bin = Eulertools::vectorToDigit(Eulertools::convertToBinary(i));
		result.push_back(bin);
	}
	
	return result;
}
