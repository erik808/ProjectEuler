#include <iostream>
#include <vector>
#include <array>
using namespace std;

bool isPentagonal(size_t number);

int main()
{
	size_t const max = 20000000;
	vector<size_t> pnts;
	size_t pent = 0;
	size_t n    = 1;
	while (pent < max)
	{
		pent = (n * ((3 * n) - 1 )) / 2;
		if (pent < max)
			pnts.push_back(pent);
		++n;
	}
	
	size_t min = max;
	size_t minTmp;
	size_t diff = 0;
	size_t sum = 0;
	for (auto const &P1: pnts)
		for (auto const &P2: pnts)
		{
			sum = P1 + P2;
			if (sum < max)
			{
				if (isPentagonal(sum))
				{
					//cout << "sum: " << P1 << " " << P2 << '\n';
					diff = (P2 < P1) ? P1 - P2 : P2 - P1;
					if (isPentagonal(diff))
					{
						cout << "diff: " << P1 << " " << P2 << " : " << diff << '\n';
						minTmp = diff;
						min    = (minTmp < min) ? minTmp : min;
					}
				}
			}
			else
				break;		
		}
	cout << min << '\n';		
}

bool isPentagonal(size_t number)
{
	size_t pent = 0;
	size_t n    = 1;
	while (pent < number)
	{
		pent = (n * ((3 * n) - 1 )) / 2;
		if (pent == number)
			return true;
		++n;
	}
	return false;
}
