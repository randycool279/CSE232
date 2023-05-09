#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int r1, r2, c1, c2;
  
  cin >> r1 >> r2 >> c1 >> c2;
  
  for (int row = c1; row <= c2; ++row) {
    for (int col = r1; col <= r2; ++col) {
      cout << row << "*" << col << "=" << row * col << ", ";
    }
    cout << endl;
  }
  
  return 0;
}