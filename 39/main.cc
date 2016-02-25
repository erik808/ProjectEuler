#include <iostream>
#include <array>
#include <cmath>

int main()
{
	size_t const length = 1001;
	
	std::array<size_t, length> lookup;
	lookup.fill(0);

	for (size_t a = 1; a != length; ++a)
		for (size_t b = 1; b != length; ++b)
			for (size_t c = 1; c != length; ++c)
			{
				if (a + b + c >= length)
					break;
				
				if (pow(a, 2) + pow(b, 2) == pow(c, 2))
					lookup[a + b + c] = lookup[a + b + c] + 1;
//				std::cout << a << ", " << b << ", " << c << std::endl;
			}

	size_t maxidx = 0;
	size_t max = 0;
	
	for (size_t idx = 0; idx != length; ++idx)
		if (lookup[idx] > max)
		{
			max = lookup[idx];
			maxidx = idx;
		}

	std::cout << maxidx << " " << lookup[maxidx] << std::endl;
	return 0;
}
