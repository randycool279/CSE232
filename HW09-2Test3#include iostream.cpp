#include <iostream>
#include <string>


bool isAdjacent(char a, char b) {
    return (a == b + 1) || (a == b - 1) || (a == b);
}

int main() {
    std::string line;
    bool first_word = true;
    while (getline(std::cin, line)) {
        std::string current_word = "";
        for (char c : line) {
            if (isalnum(c) || c == '$' || c == '&' || c == '%' || c == '/' || c == '.' || c == '-' || c == '|' || c == '{' || c == '}' || c == '<' || c == '>' || c == '=') {
                if (current_word == "") {
                    current_word += c;
                } else if (isAdjacent(c, current_word.back())) {
                    current_word += c;
                } else {
                    if (current_word.length() > 1) {
                        if (!first_word) {
                            std::cout << " ";
                        }
                        std::cout << current_word;
                        first_word = false;
                    }
                    current_word = "";
                    if (isalnum(c) || c == '$' || c == '&' || c == '%' || c == '/' || c == '.' || c == '-' || c == '|' || c == '{' || c == '}' || c == '<' || c == '>' || c == '=') {
                        current_word += c;
                    }
                }
            } else {
                if (current_word.length() > 1) {
                    if (!first_word) {
                        std::cout << " ";
                    }
                    std::cout << current_word;
                    first_word = false;
                }
                current_word = "";
            }
        }
        if (current_word.length() > 1) {
            if (!first_word) {
                std::cout << " ";
            }
            std::cout << current_word;
            first_word = false;
        }
    }
    std::cout << std::endl;
    return 0;
}
