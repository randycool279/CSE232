#include <iostream>
#include <string>

std::int64_t LocToDec(std::string const & loc) {
  std::int64_t dec = 0;
  for (char c : loc) {
    switch (c) {
      case 'a':
        dec += 1;
        break;
      case 'b':
        dec += 2;
        break;
      case 'c':
        dec += 4;
        break;
      case 'd':
        dec += 8;
        break;
      case 'e':
        dec += 16;
        break;
      case 'f':
        dec += 32;
        break;
    }
  }
  return dec;
}

std::string Abbreviate(std::string loc) {
  int a_count = 0, b_count = 0, c_count = 0, d_count = 0, e_count = 0, f_count = 0;
  for (char c : loc) {
    switch (c) {
      case 'a':
        a_count++;
        break;
      case 'b':
        b_count++;
        break;
      case 'c':
        c_count++;
        break;
      case 'd':
        d_count++;
        break;
      case 'e':
        e_count++;
        break;
      case 'f':
        f_count++;
        break;
    }
  }
  loc = "";
  while (a_count--) {
    loc += 'a';
  }
  while (b_count >= 2) {
    b_count -= 2;
    loc += 'c';
  }
  while (b_count--) {
    loc += 'b';
  }
  while (c_count >= 2) {
    c_count -= 2;
    loc += 'e';
  }
  while (d_count >= 2) {
    d_count -= 2;
    loc += 'g';
  }
  while (e_count--) {
    loc += 'e';
  }
  while (f_count >= 2) {
    f_count -= 2;
    loc += 'i';
  }
  return loc;
}



std::string DecToLoc(std::int64_t dec) {
  std::string loc = "";
  while (dec >= 32) {
    dec -= 32;
    loc += 'f';
  }
  while (dec >= 16) {
    dec -= 16;
    loc += 'e';
  }
  while (dec >= 8) {
    dec -= 8;
    loc += 'd';
  }
  while (dec >= 4) {
    dec -= 4;
    loc += 'c';
  }
  while (dec >= 2) {
    dec -= 2;
    loc += 'b';
  }
  while (dec >= 1) {
    dec -= 1;
    loc += 'a';
  }
  return Abbreviate(loc);
}
int main() {
std::string loc1, loc2;
std::int64_t dec1;

std::cout << "Give me a location string: " << std::endl;
std::cin >> loc1;
std::cout << "Give me an integer: "<< std::endl;
std::cin >> dec1;

std::cout << loc1 << " to dec: " << LocToDec(loc1) << '\n';
std::cout << loc1 << " abbreviated: " << Abbreviate(loc1) << '\n';
std::cout << dec1 << " to loc: " << DecToLoc(dec1) << '\n';

std::cout << "Give me two more location strings: ";
std::cin >> loc1 >> loc2;

std::cout << "Sum of " << loc1 << " and " << loc2 << " is: " << LocToDec(loc1) + LocToDec(loc2) << '\n';

return 0;
}