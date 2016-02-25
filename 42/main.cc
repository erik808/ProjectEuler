#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
using namespace std;

size_t wordValue(string str);

int main()
{
	ifstream file;
	string str;
	vector<string> words;
	file.open("words.txt");
	
	if (file.is_open())
	{
		while (getline(file, str, '\"'))
			if (str.compare(","))
				words.push_back(str);
	}	
	file.close();

	array<size_t, 1000> triangleLookup;
	triangleLookup.fill(0);

	size_t tNum = 0;
	size_t n    = 0;
	
	while (tNum <= triangleLookup.size())
	{
		tNum = (n * (n + 1)) / 2;
/*		cout << n << " " << tNum
		<< " " << triangleLookup.size() << '\n'; */
		if (tNum <= triangleLookup.size())
			triangleLookup[tNum] = 1;
		n++;
	}

	cout << words.size() << '\n';
	size_t ctr = 0;
	for (auto const &wrd: words)
	{
		if (triangleLookup[wordValue(wrd)])
			++ctr;			
	}
	cout << ctr << '\n';;
}


size_t wordValue(string str)
{
	size_t result = 0;
	for (auto const &chr: str)
		result += chr - 64;		
	return result;
}
