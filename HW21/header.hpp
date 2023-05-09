#ifndef HEADER_H
#define HEADER_H

#include <cstddef>


template <typename T, size_t N, size_t M>
void CopyStockPrices(T (&source)[N], T (&destination)[M])
{
    T expected[M];
    for (int i = 0; i < M; ++i) {
        T sum = 0;
        for (int j = 0; j < N; ++j) {
            if (i >= j) {
                sum += source[j] * destination[i-j];
            }
        }
        expected[i] = sum;
    }
    std::copy(expected, expected + M, destination);
}








#endif // HEADER_H
