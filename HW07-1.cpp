#include <iostream>

int ReverseDigits(int value) {
  int reversed = 0;
  while (value > 0) {
    reversed = reversed * 10 + value % 10;
    value /= 10;
  }
  return reversed;
}

int main() {
	for (int i = 0; i < 3; ++i) {
		int number;
		std::cin >> number;
		std::cout << ReverseDigits(number) << std::endl;
	}
	return 0;
}

/* MC Q2
int main(){
    char letter = 'Z';
    char & letter_2 = letter;
    --letter_2;
    std::cout << letter_2;
}*/