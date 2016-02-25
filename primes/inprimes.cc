#include "primes.ih"

bool Primes::inPrimes(size_t number)
{
	if (d_lookup[number])
		return true;
	return false;
}
