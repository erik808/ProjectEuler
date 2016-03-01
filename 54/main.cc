#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <array>

typedef std::array<std::array<std::string, 2>, 1000 > Hands;
void fill_hands(Hands &hands);
size_t score(std::string hand);
size_t value(char c);

//------------------------------------------------------------------
int main()
{
	Hands hands;
	fill_hands(hands);
	std::cout << value('J') << " " << value('4') << '\n';
	return 0;
}

//------------------------------------------------------------------
size_t value(char c)
{
	size_t val = 0;
	switch (c)
	{
	case '2': val = 2;
		break;
	case '3': val = 3;
		break;
	case '4': val = 4;
		break;
	case '5': val = 5;
		break;
	case '6': val = 6;
		break;
	case '7': val = 7;
		break;
	case '8': val = 8;
		break;
	case '9': val = 9;
		break;
	case 'J': val = 11;
		break;
	case 'Q': val = 12;
		break;
	case 'K': val = 13;
		break;
	case 'A': val = 14;
		break;
	}
	return val;
}

//------------------------------------------------------------------
size_t score(std::string &hand)
{
	size_t score = 0;

	// High card
	
	return score;
}

//------------------------------------------------------------------
void fill_hands(Hands &hands)
{
	std::ifstream ifs ("p054_poker.txt", std::ifstream::in);
	std::stringstream ss;
	size_t line = 0;
	char c;
	size_t player = 0;
	
	while (ifs.good())
	{
		c = ifs.get();
		if ((c != ' ') && (c != '\n'))
		{
			ss << c;
		}
		if (ss.str().length() == 10)
		{
			hands[line][player] = ss.str();
			player = (player) ? 0 : 1;
			ss.clear();
			ss.str("");
		}
		if (c == '\n')
			line++;		
	}
}
