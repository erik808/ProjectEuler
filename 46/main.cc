#include <iostream>
#include <vector>
#include <array>
#include "../primes/primes.h"
#include <cmath>

#define SQUARE(x) ((x) * (x))

using namespace std;

bool isSquare(size_t number);

int main()
{
	// building composites
	size_t const max = 100000;
	Primes P(max);
	vector<size_t> primes;
	P.exportPrimes(primes);
	
	array<size_t, max> comps;
	comps.fill(0);
	for (size_t idx = 1; idx < comps.size(); idx += 2)
			comps[idx] = idx;

	for (auto const &p: primes)
		comps[p] = 0;
	// finished building composites

	for (auto const &cm: comps)
		if (cm && (cm > 1))
		{
			cout << cm << '\n';
			bool foundDecomp = false;
			size_t remainder = 0;
			size_t p = 0;
			for (size_t pidx = 0; primes[pidx] < cm; ++pidx)
			{
				p = primes[pidx];
				remainder = cm - p;
				cout << " " << cm << " - "
					 << p << " = " <<  remainder << '\n';
				if (remainder % 2 == 0)
				{
					cout << "  " << remainder << "|2 " << '\n';
					remainder /= 2;					
					if (isSquare(remainder))
					{
						cout << "   sqrt(" << remainder << ")" << '\n';
						foundDecomp = true;
						break;
					}
				}
			}
			if (foundDecomp == false)
			{
				cout << cm << '\n';
				return 0;
			}
			
		}
}

bool isSquare(size_t number)
{
	for (size_t k = 1; SQUARE(k) <= number; ++k)
		if (SQUARE(k) == number)
			return true;
	return false;
}
