#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

vector<string> split(string const &s, char sep = ' ');

void print_vector(ostream &out, vector<string> const &v);

#endif // FUNCTIONS_HPP
