#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>
#include "HW13-2HEADER.hpp"

void SortByUppercase(std::vector<std::string>& words) {
    std::stable_sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        std::string a_upper, b_upper;

        std::copy_if(a.begin(), a.end(), std::back_inserter(a_upper), ::isupper);
        std::copy_if(b.begin(), b.end(), std::back_inserter(b_upper), ::isupper);

        return a_upper < b_upper;
    });
}

int SumOfOdd(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    return std::accumulate(begin, end, 0, [](int acc, int val) {
        return acc + (val % 2 != 0 ? val : 0);
    });
}

std::string DoubleToPercentString(const std::vector<double>& numbers) {
    std::vector<std::string> percentage_strings;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(percentage_strings), [](double num) {
        return std::to_string(static_cast<int>(num * 100)) + "%";
    });

    std::stringstream ss;
    std::copy(percentage_strings.begin(), percentage_strings.end(), std::ostream_iterator<std::string>(ss, " "));
    return ss.str();
}
int main() {
    std::string input;

    // SBU
    std::cout << "String";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    SortByUppercase(words);
    std::cout << "Sorted words: ";
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    //SOD
    std::cout << "Int ";
    std::getline(std::cin, input);
    std::istringstream iss2(input);
    std::vector<int> numbers(std::istream_iterator<int>{iss2}, std::istream_iterator<int>());
    int sum = SumOfOdd(numbers.begin(), numbers.end());
    std::cout << "Sum of odd integers: " << sum << std::endl;

    //DOTS
    std::cout << "Doubles ";
    std::getline(std::cin, input);
    std::istringstream iss3(input);
    std::vector<double> doubles(std::istream_iterator<double>{iss3}, std::istream_iterator<double>());
    std::string percentages = DoubleToPercentString(doubles);
    std::cout << "Percentages: " << percentages << std::endl;

    return 0;
}

/*
None of your code for this problem can use the for or while keywords.
 You also aren’t allowed to use the std::for_each algorithm. 
This constraint is to motivate you to learn and use the algorithms in <algorithm> and <numeric>.

You need to write a void function named SortByUppercase that takes a vector (of strings) and sorts them according
to only the uppercase letters in them.
Be sure to preserve the original order of the vector for words that have the same uppercase letters in them (look into stable sorts).
Example:
std::vector<std::string> words = {"wolf", "BanAna", "caRRot", "AprIcots", "BEets", "chiCkPeas", "orAngEs", "apple", "CAT", "dOG"};
std::vector<std::string> expected = {"wolf", "apple", "orAngEs", "AprIcots", "BanAna", "BEets", "CAT", "chiCkPeas", "dOG", "caRRot"};
SortByUppercase(words);
CHECK(words == expected);
// Note that "wolf" comes before "apple" 
// because neither has any uppercase letters (so the original order is preserved)
// Next comes "orAngEs" because the "AE" comes before the "AI" in "AprIcots".


Write a function named SumOfOdd that takes two iterators denoting a range (much like almost all if the algorithm functions) 
in a vector of ints. The function should return the sum of the odd integers in this range.
Example:
std::vector<int> const numbers = {1, 2, 3, 4, 5, 6, 8, 5, 2, 2, 5, 101};
CHECK(SumOfOdd(numbers.cbegin(), numbers.cend()) == 120); // 1 + 3 + 5 + 5 + 5 + 101

CHECK(SumOfOdd(numbers.begin() + 1, numbers.end() - 1) == 18); // 3 + 5 + 5 + 5

Write a function named DoubleToPercentString that takes a vector of doubles. 
The function should return a string of all the doubles converted to percentages. \
For example the double 0.5993 should be converted to "59%". Note that the percentages are truncated, not rounded.
Example:
std::vector<double> const doubles = {1, 2, 100, 200, 12.3456, 4787, 0.123};
CHECK(DoubleToPercentString(doubles) == "100% 200% 10000% 20000% 1234% 478700% 12% ");



*/