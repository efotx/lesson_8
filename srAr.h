#ifndef SRAR_H_INCLUDED
#define SRAR_H_INCLUDED

#include <cassert>

//function calculates the arithmetic mean of the interval
template <typename T>
T srAr(T *start, T *last)
{
    size_t count = 0;
    T sum = 0;
    for ( ; start != last; ++start)
    {
        ++count;
        sum += *start;
    }
    assert (count != 0);
    return sum/count;
}


#endif // SRAR_H_INCLUDED
