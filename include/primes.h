#ifndef PRIMES_H
#define PRIMES_H

#include <iostream>
#include <vector>

using namespace std;

class Primes
{
	vector<size_t> d_lookup;
	vector<size_t> d_primes;
	
public:

	Primes(size_t range);
	~Primes() = default;

	vector<size_t> getLookup(){ return d_lookup;}
	vector<size_t> getPrimes(){ return d_primes;}

	vector<size_t> primeFactorization(size_t number);

	bool inPrimes(size_t number);

	void print();
	void printLast();
};

#endif
