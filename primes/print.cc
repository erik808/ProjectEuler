#include "primes.ih"

void Primes::print()
{
	for (size_t idx = 0; idx != d_primes.size(); ++idx)
		std::cout << idx + 1 << ' ' << d_primes[idx] << '\n';
}