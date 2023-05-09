#include <iostream>
#include "HW19-Header.hpp"

int main() {
	LispExpression le(" (  one two ( three )   ) ");
	std::cout << le.PrettyPrint();

	return 0;
}