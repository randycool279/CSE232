#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

template<typename T>
T Repeat(T);

template<>
std::string Repeat<char>(char);

template<>
std::string Repeat<std::string>(std::string);

#endif // HEADER_HPP




/*In the file TemplatedFunction/functions.hpp, you need to write two templated functions.
 The first function is named Increment. It takes an arguments and returns that argument incremented (increased by 1). 
 The second function is named AddToString. It takes a reference to a constant string and a second parameter. 
 This second parameter a numeric primitive value that should be taken as a copy. 
The function returns the result of concatenation of the string with the second value.*/