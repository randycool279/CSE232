#include <iostream>
#include <string>
#include <cctype>
//gives me the functionality to use isalpha
//https://www.programiz.com/cpp-programming/library-function/cctype

using std::cin;
using std::string;
using std::cout;

int main() {
    string line;
    while (getline(cin, line)) {
        bool in_word = false;
        for (char c : line) {
            if (isalpha(c)) {
                if (!in_word) {
                    cout << c;
                    in_word = true;
                }
            } else {
                in_word = false;
            }
        }
    }
    return 0;
}
