#include "primes.h"

size_t const bound = 1000000;

int main()
{
	Primes P(bound);
	vector<size_t> primes = P.getPrimes();
	vector<size_t> lookup = P.getLookup();

	vector<size_t>::iterator p_itr = primes.begin();
	size_t sum         = 0;
	size_t maxDistance = 0;
	size_t maxPrime    = 0;
	size_t distance    = 0;
	for (; p_itr != primes.end(); ++p_itr)
	{
		sum = *p_itr;
		vector<size_t>::iterator p_sum = p_itr;
		for (++p_sum; p_sum != primes.end(); ++p_sum)
		{
			sum += *p_sum;
			if (sum >= lookup.size())
				break;
			if (lookup[sum])
			{
				distance    =  p_sum - p_itr;
				if (distance > maxDistance)
				{
					maxDistance = distance;
					maxPrime = sum;
					cout << sum << " " << maxDistance + 1<< " " << maxPrime << '\n';
				}

			}
		}
	}
}
