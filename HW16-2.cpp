#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> MaxVector(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result(std::max(vec1.size(), vec2.size()));

    auto it1 = vec1.begin();
    auto it2 = vec2.begin();
    auto result_it = result.begin();

    std::transform(it1, it1 + std::min(vec1.size(), vec2.size()), it2,
                   result_it, [](const T& a, const T& b) { 
                     return std::max(a, b); 
                     });

    std::copy(it1 + std::min(vec1.size(), vec2.size()), vec1.end(), result_it + std::min(vec1.size(), vec2.size()));
    std::copy(it2 + std::min(vec1.size(), vec2.size()), vec2.end(), result_it + std::min(vec1.size(), vec2.size()));

    return result;
}

template std::vector<int> MaxVector(const std::vector<int>& vec1, const std::vector<int>& vec2);

template std::vector<std::string> MaxVector(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2);




int main() {
    std::vector<int> const vec_a = {1, 20, -3, 7, 56, 0, -2};
    std::vector<int> const vec_b = {10, 4, -3, 8};
    std::vector<int> const expected = {10, 20, -3, 8, 56, 0, -2};
    auto result = MaxVector(vec_a, vec_b);
    assert(result == expected);
    //std::cout << "Result for vector<int>:\n" << result << "\n";

    std::vector<std::string> const vec_c = {"hello", "apple", "CSE"};
    std::vector<std::string> const vec_d = {"bye", "banana"};
    std::vector<std::string> const expected2 = {"hello", "banana", "CSE"};
    auto result2 = MaxVector(vec_c, vec_d);
    assert(result2 == expected2);
    //std::cout << "Result for vector<std::string>:\n" << result2 << "\n";

    std::cout << "All test cases passed!\n";
    return 0;
}
