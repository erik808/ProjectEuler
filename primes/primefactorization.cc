#include "primes.ih"

vector<size_t> Primes::primeFactorization(size_t number)
{
	vector<size_t> output;
	for (auto const &p: d_primes) 
	{
		if (number % p == 0)
		{
			output.push_back(p);
			while (number % p == 0)
				number /= p;
		}
	}
	return output;
}
