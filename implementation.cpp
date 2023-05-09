#include <iostream>
#include "HW11-1.hpp"

template<>
int Repeat(int arg) {
    return arg + arg;
}

template<>
std::string Repeat(char arg) {
    std::string s(1, arg);
    std::string returnVal =s + s;
    return returnVal;
}

template<>
std::string Repeat(std::string arg) {
    return arg + " " + arg;
}


int main() {
    int x;
    char y;
    std::string z;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    std::cout << Repeat<int>(x);
    std::cout << Repeat<char>(y);
    std::cout << Repeat<std::string>(z);

    return 0;
}
