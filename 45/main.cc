#include <iostream>
#include <vector>

using namespace std;

bool isPentagonal(size_t number);
bool isHexagonal(size_t number);

int main()
{
	size_t n = 285;
	size_t Tnum = 0;;
	while (true)
	{
		Tnum = (n * (n + 1)) / 2;
		
		if (isPentagonal(Tnum) && isHexagonal(Tnum))
		{
			cout << n << " " << Tnum << '\n';
			if (n > 285)
				break;
		}
		++n;
	}
}

bool isPentagonal(size_t number)
{
	size_t pent = 0;
	size_t n    = 1;
	while (pent < number)
	{
		pent = (n * ((3 * n) - 1 )) / 2;
		if (pent == number)
		{
			cout << n << " " << pent << '\n';
			return true;
		}
		++n;
	}
	return false;
}

bool isHexagonal(size_t number)
{
	size_t hex  = 0;
	size_t n    = 1;
	while (hex < number)
	{
		hex = (n * ((2 * n) - 1 ));
		if (hex == number)
		{
			cout << n << " " <<  hex << '\n';
			return true;
		}
		++n;
	}
	return false;
}
