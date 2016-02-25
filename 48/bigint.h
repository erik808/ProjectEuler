#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>

using namespace std;

class bigInt
{
	vector<size_t> d_array;
	
public:
	
	bigInt(size_t number);
	~bigInt() = default;

	void plus(bigInt &n1, bigInt &n2);

	void print();
	
private:
	
	vector<size_t> digitToVector(size_t number);
};

#endif
