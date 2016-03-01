#include <iostream>
#include <vector>

double factorial_estimate(size_t n, size_t r);

int main()
{
	double million = 1e6;
	double ans;
	size_t ctr = 0;
	for (size_t n = 1; n <= 100; ++n)
	{
		for (size_t r = 2; r < n; ++r)
		{
			ans = factorial_estimate(n,r);
			if (ans > million)
			{
				ctr++;
			}
		}
			
	}
	std::cout << ctr << std::endl;
}

double factorial_estimate(size_t n, size_t r)
{
	size_t N = n;
	size_t R = r;

	double ans = 1;

	while ((N != 1) || (R != 1))
	{
		ans *= ((double) N) / ((double) R);
		N = (N > n - r + 1) ? N - 1 : 1;
		R = (R > 1) ? R - 1 : 1;
	}
	return ans;	
}
