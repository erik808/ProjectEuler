#include <iostream>
#include <vector>
#include "eulertools.h"
#include <math.h>

int main(int argc, char **argv)
{
    std::vector<size_t> result;

    int max = 0;
    for (size_t a = 1; a <= 100; ++a)
        for (size_t b = 1; b <= 100; ++b)
        {
            result.clear();
            Eulertools::bigPow(a,b,result);
            max = std::max(max, Eulertools::sumVector(result));
        }
    std::cout << max << std::endl;
    
    return 0;
}
