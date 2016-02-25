#include "primes.ih"

void Primes::printLast()
{
	vector<size_t>::iterator idx = d_primes.end() - 1;
	cout << *idx << '\n';
}