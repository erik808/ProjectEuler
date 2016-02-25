#include <iostream>
#include <vector>

using namespace std;

vector<size_t> digitToVector(size_t number);
void addVectors(vector<size_t> &n1, vector<size_t> &n2, vector<size_t> &dest);
void multVector(vector<size_t> &n1, size_t number, vector<size_t> &dest);

size_t const cutoff = 15;

int main()
{

	vector<size_t> num1;
	vector<size_t> num2;
	vector<size_t> tmp;
	vector<size_t> storage;
	storage = {0};
	
	for (size_t num = 1; num <= 1000; ++num)
	{
		num1 = digitToVector(num);
		for (size_t it = 0; it != num-1; ++it)
		{
			multVector(num1, num, tmp);
			num1 = tmp;			
		}
		addVectors(num1, storage, tmp);
		storage = tmp;
	}
	
	for (auto const &it: storage)
		cout << it << " ";
	cout << '\n';	
}

void multVector(vector<size_t> &n1, size_t number, vector<size_t> &dest)
{
	vector<size_t> tmp;
	tmp.push_back(0);
	for (size_t it = 0; it != number; ++it)
	{
		addVectors(n1, tmp, dest);
		tmp = dest;
	}
}

void addVectors(vector<size_t> &n1, vector<size_t> &n2, vector<size_t> &dest)
{

	size_t size1 = n1.size();
	size_t size2 = n2.size();
	
	vector<size_t> *max = (size1 > size2) ? &n1 : &n2;
	vector<size_t> *min = (size1 > size2) ? &n2 : &n1;

	dest = *max;
	
	vector<size_t>::reverse_iterator ritMax  = max->rbegin();
	vector<size_t>::reverse_iterator ritMin  = min->rbegin();
	vector<size_t>::reverse_iterator ritDest = dest.rbegin();

	for (; ritMax != max->rend(); ++ritMax)
	{
		if (ritMin < min->rend())		
			*ritDest = *ritDest + *ritMin;

		if (*ritDest > 9)
		{
			*ritDest %= 10;
			if ((ritDest + 1) != dest.rend())
				*(ritDest+1) += 1;
			else
				dest.insert(dest.begin(), 1);
		}
				
		++ritMin;
		++ritDest;
	}

	while (dest.size() > cutoff)
		dest.erase(dest.begin());
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
