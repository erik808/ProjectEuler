#include <iostream>
#include <vector>
#include "eulertools.h"

static const size_t maxIter = 50;
static const size_t maxNum  = 10000;

int main(int argc, char **argv)
{

    size_t countLychrel = 0;
    for (size_t num = 1; num <= maxNum; ++num)
    {
        
        std::vector<size_t> result =
            Eulertools::digitToVector(num);

        std::vector<size_t> tmp1, tmp2;
        size_t iter = 0;
        while (iter < maxIter)
        {
            tmp1.clear();
            tmp2.clear();
            
            Eulertools::reverseVector(result, tmp1);
            Eulertools::addVectors(result, tmp1, tmp2);
            result = tmp2;

            if (Eulertools::isPalindrome(result))
                break;
            
            iter++;
        }
        
        if (iter == maxIter)
            countLychrel++;
    }

    std::cout << countLychrel << std::endl;

    
    return 0;
}
