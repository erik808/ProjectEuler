/* Pandigital numbers 
   Take the number 192 and multiply it by each of 1, 2 and 3:
   192x1 = 192
   192x2 = 384
   192x3 = 576

   192384576

   918273645

   What is the largest 1-9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2,...,n), where n > 1?
*/
 
#include <iostream>
#include <vector>
using namespace std;

vector<int> compute(int number, vector<int> &array);
bool isPandigital(vector<int> &array);
bool biggerThan(vector<int> &array1, vector<int> &array2);
int order(int number);
void printNumber(vector<int> &array);

int main()
{
	int number;
	int n;
	vector<int> maximum = {0,0,0,0,0,0,0,0,0};
	vector<int> array;
	vector<int> result;
	for (number = 1; number != 10000; ++number)
	{
		for (n = 2; n != 10; n++)
		{
			array.clear();			
			for (int i = 1; i != n+1; i++)
				array.push_back(i);
			
			result.clear();
			result = compute(number, array);
			
			if (result.size() != 9) continue;

			if (isPandigital(result) && biggerThan(result, maximum))
			{
				printNumber(result);
				maximum = result;
			}
		}
	} 
	return 0;
}

vector<int> compute(int number, vector<int> &array)
{
	vector<int> result;
	int digit, ord;
	for (auto const &k: array)
	{
		digit = number * k;
		ord = order(digit);
		while (ord)
		{
			result.push_back(digit / ord);
			digit %= ord;
			ord /= 10;				
		}
	}
	return result;
}

bool isPandigital(vector<int> &array)
{
	vector<int> dum;
	for (int i = 0; i != 10; ++i)
		dum.push_back(0); // dum contains 10 zeros;
	
	for (auto const &a: array)
	{
		dum[a]++;
		if (dum[a] > 1)
			return false;
	}
	
	for (int i = 1; i != 10; ++i)
		if (dum[i] != 1)
			return false;
	return true;
}

bool biggerThan(vector<int> &array1, vector<int> &array2)
{
	if (array1.size() != array2.size()) return false;
	int num1 = 0;
	int num2 = 0;
	int order = 100000000;
	for (size_t idx = 0; idx != array1.size(); idx++)
	{
		num1 += order * array1[idx];
		num2 += order * array2[idx];
		order = order / 10;
	}
	if (num1 >= num2)
		return true;
	else
		return false;
}

int order(int number)
{
	int o = 1;
	while (number >= o)
		o *= 10;
	return o / 10;
}


void printNumber(vector<int> &array)
{
	for (auto const &a: array)
		cout << a << " ";
	cout << endl;
	return;
}
