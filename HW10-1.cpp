#include <iostream>
#include <string>

std::string SharedLetters(const std::string& w1, std::string w2, const std::string* const w3) {
    std::string result;
    long unsigned int len = std::max(std::max(w1.length(), w2.length()), w3->length());
    for (long unsigned int i = 0; i < len; i++) {
        int count = 0;
        if (i < w1.length() && i < w2.length() && w1[i] == w2[i]) 
            count++;
        if (i < w1.length() && i < w3->length() && w1[i] == (*w3)[i]) 
            count++;
        if (i < w2.length() && i < w3->length() && w2[i] == (*w3)[i]) 
            count++;
        result += std::to_string(count) + ",";
    }
    return result;
}

int main() {
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3;
    std::cout << SharedLetters(w1, w2, &w3) << std::endl;
    return 0;
}
