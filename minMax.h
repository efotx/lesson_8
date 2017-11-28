#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED

template <typename It, typename T>
std::pair<T, T> minMax (It first, It last)
{
    T minimum = *first;
    T maximum = *first;
    for ( ; first != last; ++first)
    {
        if (*first < minimum)
        {
            minimum = *first;
        }
        if (maximum < *first)
        {
            maximum = *first;
        }
    }
    return std::make_pair(minimum, maximum);
}

#endif // MINMAX_H_INCLUDED
