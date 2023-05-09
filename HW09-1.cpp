#include <iostream>
#include <string>
#include <algorithm>


std::string scramble(const std::string& word) {
    if (word.size() <= 2) {
        return word; 
    }
    std::string middle = word.substr(1, word.size() - 2);
    reverse(middle.begin(), middle.end());
    //using <algorithm> I can reverse certain parts of std::string
    //https://stackoverflow.com/questions/4951796/how-to-reverse-an-stdstring
    return word.substr(0, 1) + middle + word.substr(word.size() - 1, 1);
}

int main() {
    std::string word;
    int count = 0; 
    while (std::cin >> word) {
        if (count == 10) {
            std::cout << std::endl;
            count = 0;
        }
        if (count == 0) {
            std::cout << scramble(word);
        } else {
            std::cout << " " << scramble(word);
        }
        count++;
    }
    
    if (count % 10 != 0) {
        std::cout << " ";
    }
    std::cout << std::endl; 
    return 0;
}








