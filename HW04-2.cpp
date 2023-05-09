// WRITE YOUR CODE HERE
/*Write a program, named Octal/main.cpp that takes a positive integer from standard input and writes three values to standard output: the number in decimal, in hexadecimal and in octal (each on their own line).
We strongly recommend consulting the C++ documentation for suggestions on how to modify the std::cout stream to make this happen.*/
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::dec;
using std::hex;
using std::oct;


int main(){
  int n;
  cin >> n;
  cout << dec << n << endl;
  // found this in c++reference
  // https://en.cppreference.com/w/cpp/io/manip/hex
  cout << hex << n << endl;
  cout << oct << n << endl;
  return 0;


}