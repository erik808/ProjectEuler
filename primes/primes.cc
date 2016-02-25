#include "primes.ih"
#include <array>

#ifndef SQUARE
#define SQUARE(x) ((x) * (x))
#endif

Primes::Primes(size_t range)
{
	for(size_t it = 0; it != range; ++it)
		d_lookup.push_back(it);
		
	size_t q     = 2;
	size_t delta = 2;
    size_t sigma;
	size_t current = 0;
    while ((sigma = SQUARE(q)) <= range) 
    {
        for (size_t qStar = sigma; qStar <= range; qStar += delta) 
            if (d_lookup[qStar])
                d_lookup[qStar] = 0;
		
//        q = nextPrime(primes, q);
		current = q;
		for (++current; current <= range; ++current)
			if (d_lookup[current])
			{
				q = current;
				break;
			}
        delta = 2 * q;
    }

	for (auto const &a: d_lookup)
		if (a > 1)
			d_primes.push_back(a);
}
