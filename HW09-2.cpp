#include <iostream>
#include <string>

bool is_adjacent(char a, char b) {
    int x = a;
    int y = b;
    return std::abs(x - y) <= 1;
}

int main() {
    std::string word;
    while (std::cin >> word) {
        std::string result;
        for (int i = 0; i < word.size(); i++) {
            if (i == 0 || is_adjacent(word[i], result.back())) {
                result += word[i];
            } else if (is_adjacent(word[i], word[i-1])) {
                result.back() = word[i];
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}