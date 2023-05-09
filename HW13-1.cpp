#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "HW13-1Header.hpp"

std::vector<int>::const_iterator FindSmallestIndexRange(const std::vector<int>& numbers, int start, int end) {
    end = std::min(end + 1, static_cast<int>(numbers.size())); 
    return std::min_element(numbers.begin() + start, numbers.begin() + end);
}


int main() {
    std::vector<int> numbers;
    std::cout << "Enter integers for the vector, separated by spaces, and press Enter: ";
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
        if (std::cin.peek() == '\n') {
            break;
        }
    }

    int start, end;
    std::cout << "Enter the start and end indices for the range, separated by a space: ";
    std::cin >> start >> end;

    auto smallest = FindSmallestIndexRange(numbers, start, end);
    std::cout << "The smallest element in the range is: " << *smallest << std::endl;

    std::vector<double> doubles = {5.6, 2.3, 12, 19};
    DoubleIteratorRange(doubles.begin(), doubles.end());

    std::cout << "Doubled elements: ";
    for (const auto& value : doubles) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
You need to write function named FindSmallestIndexRange that takes vector (of ints) and two integers (denoting a range of indexes). 
This function should return an iterator pointer at the smallest element in the vector within the range denoted (inclusive).
 If multiple elements tie for the smallest, return the first one. 
 Please note that the last argument may denote a position beyond the end of the vector, 
 so make sure you don’t read past the end of the vector. You can assume the range includes at least one element.
std::vector<int> data = {6, 1, 5, 4, 3, 2, -1};
auto iter_smallest = FindSmallestIndexRange(data, 2, 5);
// the range of the vector bounded by the integers is {5, 4, 3, 2}
// the smallest element in this range is the 2. 
// So an iterator pointing at the 5th position in data should be returned


You need to write a templated void function (named DoubleIteratorRange) that takes two non-const forward iterators 
to a container of a numeric type (e.g. int or double). 
The function should double all the elements in the range denoted by the iterators.
The end iterator denotes one-past-the-end of the range (please don’t dereference it as it may point at one-past-the-end of the vector).
You can assume the range includes at least one element.
std::vector<float> data = {5.6, 2.3, 12, 19};
DoubleIteratorRange(data.begin(), data.end());
std::vector<float> expected = {11.2, 4.6, 24, 38};
CHECK(data == expected);








*/