#include <iostream>
#include "../primes/primes.h"
#include <vector>
#include <array>
using namespace std;

vector<size_t> digitToVector(size_t number);
array<size_t, 10> digitMap(vector<size_t> &digit);
void printVec(vector<size_t> vec);

size_t const maxbound = 10000;

int main()
{
	Primes P(maxbound);
	vector<size_t> list;
	P.exportPrimes(list);

	vector<size_t> vecPrime;
	array<size_t, 10> perm1;
	array<size_t, 10> perm2;
	
	while (*list.begin() <= 999)
		list.erase(list.begin());

	for (auto const &l1: list)
	{
		vecPrime  =  digitToVector(l1);
		perm1     =  digitMap(vecPrime);
		bool permFlag = false;
		size_t diff;
		size_t prev;
		for (auto const &l2: list)
			if (l1 != l2)
			{
				vecPrime  =  digitToVector(l2);
				perm2     =  digitMap(vecPrime);
				if ( (perm1 == perm2) && permFlag && prev != l2 &&
					 (diff == ((l2 > prev) ? l2 - prev : prev - l2)) )
				{
					cout << l1 << " " << prev << " " << l2 << '\n';
					cout << diff << '\n';
					cout << ((l2 > prev) ? l2 - prev : prev - l2) << '\n';
					return 0;
				}
				
				if ((perm1 == perm2))
				{
					permFlag = true;
					diff = (l2 > l1) ? l2 - l1 : l1 - l2;
					prev = l2;
				}

			}
	}
}

array<size_t, 10> digitMap(vector<size_t> &digit)
{
	array<size_t, 10> permLookup;
	permLookup.fill(0);
	for (auto const &dig: digit)
		permLookup[dig] += 1;
	return permLookup;
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


void printVec(vector<size_t> vec)
{
	for (auto const &v: vec)
		cout << v << " ";
	cout << endl;
}
