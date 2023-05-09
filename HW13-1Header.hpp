#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

std::vector<int>::const_iterator FindSmallestIndexRange(const std::vector<int>& numbers, int start, int end);

template <typename ForwardIt>
void DoubleIteratorRange(ForwardIt begin, ForwardIt end) {
    std::transform(begin, end, begin, [](auto num) { return num * 2; });
}

#endif // ITERATORS_HPP
