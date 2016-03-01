#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <array>

typedef std::array<std::array<std::string, 2>, 1000 > Hands;
void fill_hands(Hands &hands);

//------------------------------------------------------------------
int main()
{
	Hands hands;
	fill_hands(hands);
	std::cout << hands[0][0] << " " << hands[0][1] << std::endl;
	return 0;
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
