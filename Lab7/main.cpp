
#include <iostream>
#include <string>
#include <vector>
#include "functions.hpp"

int main() {
    std::string input_string;
    std::cout << "Give me a string to split: " << std::endl;
    std::getline(std::cin, input_string);

    char separator;
    std::cout << "What character should I split on: "<< std::endl;
    std::cin >> separator;

    std::vector<std::string> split_result = split(input_string, separator);
    print_vector(std::cout, split_result);

    return 0;
}

