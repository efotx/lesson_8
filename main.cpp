#include <iostream>
#include <vector>
#include "srAr.h"
#include "minMax.h"
#include "scopedPtr.h"


int main()
{
    int a[] = {1, 5, 6, 7, -3, -6, 6};
    int *aptr = a;
    std::cout << srAr(aptr, aptr + 7) << std::endl;
    std::vector<int> v1 = {1, 2, 5, 8, -4, -6, 90};
    std::vector<double> v2 = {3.5, 6.6, -1.4, 7.1};
    std::pair<int, int> p = minMax<std::vector<int>::iterator, int>(v1.begin(), v1.end());
    std::pair<double, double> p2 = minMax<std::vector<double>::iterator, double>(v2.begin(), v2.end());
    std::cout << p.first << " " << p.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;
    scopedPtr<std::vector<int>> smart(new std::vector<int>(v1));
    return 0;
}
