#include "HW19-Header.hpp"
#include <sstream>
#include <cctype>

LispExpression::LispExpression(const std::string& input) : input1(input) {}

std::string LispExpression::PrettyPrint() const {
    size_t index = 0;
    std::stringstream output;
    while (index < input1.size()) {
        if (prettyPrint_rec(input1, index, 0, output)) {
            break;
        }
    }
    return output.str();
}

bool LispExpression::prettyPrint_rec(const std::string& input, size_t& index, int indentation, std::stringstream& output) const {
    std::string single_word;

    while (index < input.size()) {
        char ch = input[index];

        if (std::isspace(ch)) {
            index++;
        } else if (ch == '(') {
            index++;
            output << std::string(indentation, ' ') << "(\n";
            if (prettyPrint_rec(input, index, indentation + 1, output)) {
                return true;
            }
        } else if (ch == ')') {
            index++;
            output << std::string(indentation - 1, ' ') << ")\n";
            return (indentation == 1);
        } else {
            single_word.clear();
            while (!std::isspace(ch) && ch != '(' && ch != ')' && index < input.size()) {
                single_word.push_back(ch);
                index++;
                ch = input[index];
            }
            output << std::string(indentation, ' ') << single_word << "\n";
        }
    }

    return false;
}
