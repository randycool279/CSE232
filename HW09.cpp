#include <iostream>
#include <string>


int main() {
    std::string s;
    while (std::cin >> s) {
        for (long unsigned int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[i] == s[i + 1] || s[i] == s[i + 1] - 1 || s[i] == s[i + 1] + 1) {
                    std::cout << s[i];
                }
            } else if (i == s.size() - 1) {
                if (s[i] == s[i - 1] || s[i] == s[i - 1] - 1 || s[i] == s[i - 1] + 1) {
                    std::cout << s[i];
                }
            } else {
                if (s[i] == s[i - 1] || s[i] == s[i - 1] - 1 || s[i] == s[i - 1] + 1 || s[i] == s[i + 1] || s[i] == s[i + 1] - 1 || s[i] == s[i + 1] + 1) {
                    std::cout << s[i];
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
