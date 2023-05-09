#include <iostream>
#include <string>



int main() {
    std::cout << "Give me a secret word: "<< std::endl;
    std::string secretWord;
    std::cin >> secretWord;

    std::cout << "Give me a guess: "<<std::endl;

    std::string guess;
    std::string lastHint = ".....";
    int guessesLeft = 6;
    while (guessesLeft > 0 && std::cin >> guess) {
        guessesLeft--;
        if (guess == secretWord) {
            std::string hint = "";
            for (int i = 0; i < 5; i++) {
                hint += guess[i];
            }
            std::cout << hint << std::endl;
            std::cout << "You Win!" << std::endl;
            return 0;
        }
        else if (guessesLeft == 0) {
            std::string Final_hint = "";
            for (int i = 0; i < 5; i++) {
                if (guess[i] == secretWord[i]) {
                    Final_hint += guess[i];
                }
                else if (secretWord.find(guess[i]) != std::string::npos) {
                    Final_hint += "?";
                }
                else {
                    Final_hint += ".";
                }
            }
            std::cout << Final_hint << std::endl;
            std::cout << "You Lose." << std::endl;
            return 0;
        }
        else {
            std::string hint = "";
            for (int i = 0; i < 5; i++) {
                if (guess[i] == secretWord[i]) {
                    hint += guess[i];
                }
                else if (secretWord.find(guess[i]) != std::string::npos) {
                    hint += "?";
                }
                else {
                    hint += ".";
                }
            }
            std::cout << hint << std::endl;
            lastHint = hint;
            std::cout << "Give me a guess: "<<std::endl;
        }
    }
    std::cout << "You Lose." << std::endl;
    return 0;
}
