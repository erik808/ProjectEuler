#include <iostream>
#include <sstream>
#include <vector>
#include "eulertools.h"

using namespace Eulertools;
using namespace std;

int main()
{
    string lookupstr0, lookupstr1;
	vector<size_t> lookup_vec(10, 0);
	size_t mult = 6;
	size_t end  = 100000000;
	size_t number0, number1;
	size_t ord0;
	vector<size_t> number_vec;
		
	for (number0 = 1; number0 != end; ++number0)
	{
		ord0    = order(number0);
		number1 = number0;

		if (order(number0 * mult) != ord0)
			continue;		
		
		number_vec = digitToVector(number0);

		// fill lookup vector
		for (auto &n: number_vec) lookup_vec[n]++;
		
		// put lookup vec in string and clear lookup vec
		lookupstr0 = vec2str(lookup_vec);

		// reset lookup vec
		fill(lookup_vec.begin(), lookup_vec.end(), 0);

		size_t i;
		for (i = 2; i <= mult; ++i)
		{
			number1 = i * number0;
			
			// break if number has more digits
			if (order(number1) != ord0) break;
			
			number_vec = digitToVector(number1);
			
			for (auto &n: number_vec) lookup_vec[n]++;     // fill
			lookupstr1 = vec2str(lookup_vec);              // to string
			fill(lookup_vec.begin(), lookup_vec.end(), 0); // reset
			
			if (lookupstr0.compare(lookupstr1) != 0)
				break;		
		}
		if (i > mult)
		{
			number1 = number0;
			for (i = 2; i <= mult; ++i)
			{
				number1 = i * number0;
				cout << number0 << " " << number1 << " " << i << endl;
			}
			break;
		}
	}
	return 0;
}
