#include "bigint.h"
//work in progress
bigInt::bigInt(size_t number)
{
	d_array = digitToVector(number);
}

void plus(bigInt &n1, bigInt &n2)
{
	
}

void bigInt::print()
{
	for (auto const &i: d_array)
		cout << i << " ";
	cout << '\n';
}

vector<size_t> bigInt::digitToVector(size_t number)
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
