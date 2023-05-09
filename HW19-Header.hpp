#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

/*
Lisp is a programming language that makes heavy use of parentheses, see: https://xkcd.com/297/.
 In this problem, write a class named LispExpression that supports pretty printing;
Example:
LispExpression le(" (  one two ( three )   ) ");
std::cout << le.PrettyPrint();
This program should output:
(
 one
 two
 (
  three
 )
)
The string will have each word/token separated by whitespace. The output stream should have each token on its own line. Indented (with single space characters) to show the nestedness of the elements within parentheses. A LispExpression ends when it encounters its closing brace. Be sure to include your code in LispExpression/header.hpp and LispExpression/implementation.cpp.
LispExpression
*/
class LispExpression {
public:
    explicit LispExpression(const std::string& input);

    std::string PrettyPrint() const;

private:
    bool prettyPrint_rec(const std::string& input, size_t& index, int indentation, std::stringstream& output) const;

    std::string input1;
};

#endif // HEADER_HPP
