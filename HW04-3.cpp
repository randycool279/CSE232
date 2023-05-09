/*Write a program in SignificantFigures\main.cpp that takes in a floating point value and outputs that value with 1, 3, and 5 decimal places shown in scientific notation. 
Please make each value right aligned with space characters with each line having a length of 12.*/
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::scientific;
using std::setprecision;
using std::setw;
using std::right;



int main(){


    double val;
    cin >> val;

    cout << setprecision(1) << setw(12) << right << scientific << val << endl;
    cout << setprecision(3) << setw(12) << right << scientific << val << endl;
    cout << setprecision(5) << setw(12) << right << scientific << val << endl;
    return 0;
}