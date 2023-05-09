#include <iostream>
// WRITE YOUR CODE HERE

void Double(int& num) {
    num *= 2;
}

int main() {
	int x = 7;
	Double(x);
	std::cout << x << std::endl;
}
