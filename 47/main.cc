#include <iostream>
#include <vector>
#include "../primes/primes.h"

using namespace std;

int main()
{
	size_t const max = 1000000;
	Primes P(100000);
	cout << "constructed primes\n";
	size_t const len = 4;
	vector<size_t> pfact;
	size_t sz = 0;
	for (size_t n = 1; n != max - len; ++n)
	{
		pfact     =  P.primeFactorization(n);
		sz        =  pfact.size();

		if (sz != len)
			continue;
		
		bool flag =  true;
		for (size_t k = 1; k != len; ++k)
		{
			pfact  =  P.primeFactorization(n + k);
			if (pfact.size() == sz && flag)
				flag = true;
			else
				flag = false;
		}
		if (flag)
		{
			for (size_t k = 0; k != len; ++k)
			{
				pfact  =  P.primeFactorization(n + k);
				std::cout << n + k << "   ";
				for (auto const &f: pfact)
					cout << f << " ";
				cout << '\n';
			}
			break;
		}			
	}
}
