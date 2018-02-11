#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <fstream>

static const size_t numcards = 5;
static const size_t strlen   = 10;
static const size_t numbins  = 10;
static const size_t maxvals  = 15;
static const size_t numhands = 1000;

typedef std::array<std::array<std::string, 2>, numhands > Hands;

enum Bins // Rankings 
{
    HC = 0,
    OP, TP, TK,
    ST, FL, FH,
    FK, SF, RF
};

void fillHands(Hands &hands);

int  score(std::string const &str,
           std::vector<int> &ranking,
           std::vector<int> &lookup);

int  compare(std::vector<int> const &rank1,
             std::vector<int> const &rank2);

int  compareHighcards(std::vector<int> const &lookup1,
                      std::vector<int> const &lookup2);

int  value(char chr);
int  suitValue(char chr);

void split(std::string const &str,
           std::string &values,
           std::string &suits);

int  buildLookup(std::string const &Str, std::vector<int> &lookup);

int  highCard(std::vector<int> const &lookup);

int  pairs(std::vector<int> const &lookup,
           std::vector<int>  &ranking);

int  fullhouse(std::vector<int> &ranking);

int  flush(std::string const &str,
           std::vector<int> const &lookup,
           std::vector<int> &ranking);

int  straight(std::vector<int> const &lookup,
              std::vector<int>  &ranking);

int  straightflush(std::vector<int> &ranking);

void printRanking(std::vector<int> const &ranking);

//------------------------------------------------------------------
int main(int argc, char **argv)
{
    Hands hands;

    fillHands(hands);
    
    int deck1wins = 0;
    int deck2wins = 0;
    
    std::string str1, str2;
    for (size_t idx = 0; idx != numhands; ++idx)
    {
        str1 = hands[idx][0];
        str2 = hands[idx][1];

    
        std::vector<int> rank1(numbins, false);
        std::vector<int> rank2(numbins, false);
        std::vector<int> lookup1(maxvals, 0);
        std::vector<int> lookup2(maxvals, 0);

        score(str1, rank1, lookup1);

        printRanking(rank1);

        score(str2, rank2, lookup2);

        printRanking(rank2);

        int result = compare(rank1, rank2);

        if (result == 3)
            result = compareHighcards(lookup1, lookup2);
    
        assert(result != 3);

        deck1wins = (result == 1) ? deck1wins + 1 : deck1wins;
        deck2wins = (result == 2) ? deck2wins + 1 : deck2wins;
        
        std::cout << std::endl;
        std::cout << " deck1wins " << deck1wins << std::endl;
        std::cout << " deck2wins " << deck2wins << std::endl;
    }
}

//------------------------------------------------------------------
int score(std::string const &str, std::vector<int> &ranking,
          std::vector<int> &lookup)
{
    if (str.size() != strlen)
    {
        std::cout << "WARNING: wrong string length!" << std::endl;
        return -1;
    }

    buildLookup(str, lookup);

    ranking[HC] = highCard(lookup);
    
    pairs(lookup, ranking);

    fullhouse(ranking);

    straight(lookup, ranking);
    
    flush(str, lookup, ranking);

    straightflush(ranking);

    return 0;
}

//------------------------------------------------------------------
// 1: rank1 wins
// 2: rank2 wins
// 3: tie
int compare(std::vector<int> const &rank1,
            std::vector<int> const &rank2)
{
    for (size_t idx = numbins; idx--;)
    {
        if (rank1[idx] > rank2[idx])
            return 1;
        else if (rank1[idx] < rank2[idx])
            return 2;
    }    
    return 3;
}

//------------------------------------------------------------------
int  compareHighcards(std::vector<int> const &lookup1,
                      std::vector<int> const &lookup2)
{
    for (size_t idx = maxvals; idx--; )
    {
        if ((lookup1[idx]) > 0 && (lookup2[idx] > 0))
        {} // do nothing
        else if (lookup1[idx] > 0)
            return 1;
        else if (lookup2[idx] > 0)
            return 2;
        
    }
    
    return 3;
}

//------------------------------------------------------------------
int highCard(std::vector<int> const &lookup)
{
    int result = 0;
    int loc = 0;
    for (auto &lk: lookup)
        if (lk > 0)
        {
            loc = &lk - &lookup[0];
            result = std::max(result, loc);
        }

    return result;
}

//------------------------------------------------------------------
int pairs(std::vector<int> const &lookup, std::vector<int> &ranking)
{
    int value   = 0;
    int pairctr = 0;
    
    for (auto &lk: lookup)
    {
        value =  &lk - &lookup[0];
        if (lk == 2) // pair
        {
            pairctr++;

            if (pairctr >= 2) // two pair
                ranking[TP] = value;
            else
                ranking[OP] = value;
            
        }
        else if (lk == 3) // three of a kind
        {
            ranking[TK] = value;
        }
        else if (lk == 4) // four of a kind
        {
            ranking[FK] = value;
        }
    }

    return 0;
}

//------------------------------------------------------------------
int flush(std::string const &str,
          std::vector<int> const &lookup,
          std::vector<int> &ranking)
{
    std::string values, suits;
    split(str, values, suits);

    std::vector<int> suitLookup(5,0);
    for (auto &st: suits)
        suitLookup[suitValue(st)] += 1;

    for (auto &sl: suitLookup)
    {
        if (sl == 5)
            ranking[FL] = highCard(lookup);            
    }

    return 0;
}

//------------------------------------------------------------------
int  straight(std::vector<int> const &lookup,
              std::vector<int>  &ranking)
{
    int contig = 0;
    int value  = 0;
    for (auto &lk: lookup)
        if (lk == 1)
        {
            contig++;
            if (contig == 5)
            {
                value = &lk - &lookup[0];
                ranking[ST] = value;
            }
        }
        else
            contig = std::max(contig - 1, 0);

    return 0;
}

//------------------------------------------------------------------
int straightflush(std::vector<int> &ranking)
{
    if ( (ranking[ST] > 0) && (ranking[FL] > 0) )
    {
        assert(ranking[ST] == ranking[FL]);
        
        if (ranking[ST] == 14)
            ranking[RF] = ranking[ST];
        else
            ranking[SF] = ranking[ST];
        
        ranking[ST] = 0;
        ranking[FL] = 0;
    }
    return 0;
}

//------------------------------------------------------------------
int fullhouse(std::vector<int> &ranking)
{
    if ( (ranking[OP] > 0) && (ranking[TK] > 0) )
    {
        ranking[FH] = ranking[TK];
    }
    return 0;
}

//------------------------------------------------------------------
int buildLookup(std::string const &str,
                std::vector<int> &lookup)
{
    assert(lookup.size() >= 15);
    
    std::string values, suits;
    split(str, values, suits);
    
    for (auto &el: values)
        lookup[value(el)] += 1; // 1-based
    
    std::cout << std::endl;
    std::cout << str << " --- ";
    for (auto &el: lookup)
    {
        std::cout << el;
    }
    std::cout << std::endl << std::endl;
    
    return 0;
}

//------------------------------------------------------------------
int value(char chr)
{
    int value = 0;
    switch (chr)
    {
    case 'T':
        value = 10;
        break;
    case 'J':
        value = 11;
        break;
    case 'Q':
        value = 12;
        break;
    case 'K':
        value = 13;
        break;
    case 'A':
        value = 14;
        break;
    default:
        value = chr - '0';
    }
    
    if ((value < 2) || (value > 14))
    {
        std::cout << "WARNING: wrong input char!" << std::endl;
        return -1;
    }


    return value;
}

//------------------------------------------------------------------
int suitValue(char chr)
{
    int value = 0;
    switch (chr)
    {
    case 'D':
        value = 1;
        break;
    case 'C':
        value = 2;
        break;
    case 'S':
        value = 3;
        break;
    case 'H':
        value = 4;
        break;
    }
    
    return value;
}

//------------------------------------------------------------------
void split(std::string const &str,
           std::string &values,
           std::string &suits)
{
    std::stringstream vls, sts;
    for (int i = 0; i < (int) strlen; i+=2)
    {
        vls << str[i];
        sts << str[i+1];
    }
    values = vls.str();
    suits  = sts.str();
}

//------------------------------------------------------------------
void printRanking(std::vector<int> const &ranking)
{
    std::vector<std::string> bins = {
        "HC",
        "OP", "TP", "TK",
        "ST", "FL", "FH",
        "FK", "SF", "RF" };

    for (auto &bn: bins)
        std::cout << std::setw(3) << bn;

    std::cout << std::endl;
    
    for (auto &el: ranking)
        std::cout << std::setw(3) << el;

    std::cout << std::endl;

}

//------------------------------------------------------------------
void fillHands(Hands &hands)
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
