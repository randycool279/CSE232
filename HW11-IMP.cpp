#include <iostream>
#include <string>
#include "HW11-IMP.hpp"

int Repeat(int input) {
  auto x =  input * 2;
  return x;
}

std::string Repeat(char input) {
  auto y =  std::string(2, input);
  return y;
}

std::string Repeat(std::string input) {
  auto z =  input + " " + input;
  return z;
}

int main() {
    int x;
    char y;
    std::string z;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;
    /*
    decltype(auto) result1 = Repeat(x);
    decltype(auto) result2 = Repeat(y);
    decltype(auto) result3 = Repeat(z);
    std::cout << "result1 has type: " << typeid(result1).name() << std::endl;
    std::cout << "result2 has type: " << typeid(result2).name() << std::endl;
    std::cout << "result3 has type: " << typeid(result3).name() << std::endl;
    
    auto result1 = Repeat(x);
    auto result2 = Repeat(y);
    auto result3 = Repeat(z);

    std::cout << result1 << std::endl;
    if (typeid(result1) == typeid(int)){
        std::cout<< "True" <<std::endl;
    }
    std::cout << result2 << std::endl;
     if (typeid(result2) == typeid(std::string)){
        std::cout<< "True" <<std::endl;
    }
    
    std::cout << result3 << std::endl;
     if (typeid(result3) == typeid(std::string)){
        std::cout<< "True" <<std::endl;
    }
    */

    std::cout << Repeat(x) << std::endl;
    std::cout << Repeat(y) << std::endl;
    std::cout << Repeat(z) << std::endl;
    return 0;
}
