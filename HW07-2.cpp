#include <iostream>

void OnlyEvenDigits(int * num) {
    int result = 0;
    int multiplier = 1;
    int original = *num;
    while (original > 0) {
        int digit = original % 10;
        if (digit % 2 == 0 && digit != 0) {
            result += digit * multiplier;
            multiplier *= 10;
        }
        original /= 10;
    }
    *num = result;
}

int main() {
    int x;
    while (std::cin >> x) {
        OnlyEvenDigits(&x);
        std::cout << x << std::endl;
    }
    return 0;
}
/*In OnlyEvenDigits/main.cpp, you need to write two functions (very similar to the previous coding problem). 
You need to write a function named OnlyEvenDigits that is a void function (meaning it doesn’t return a value). 
Instead this function takes a pointer to a positive int (and it changes that int in the course of its execution).
 It should change the int pointed at to only hold positive even digits (i.e. 2, 4, 6, and 8). 
 You should also include a main function that reads from standard input integers
 and prints those integers with only even digits until the end-of-file is encountered.
You can assume that every integer tests has at least one positive even digit.*/