#include <iostream>
#include<math.h>
//discoverd abs() and <math.h> from:
//https://cplusplus.com/reference/cmath/
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string temp1, temp2, temp3;
    cin >> temp1 >> temp2 >> temp3;
    float temp1F,temp2F,temp3F;
    temp1F = stof(temp1.substr(0,temp1.size()-1));
    //discovered stof from:
    //https://www.programiz.com/cpp-programming/string-float-conversion
    //discovered substr from: --> used for string handling so I can remove "F" from input   
    //https://www.geeksforgeeks.org/substring-in-cpp/
    //entire function found from:
    //https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string
    temp2F = stof(temp2.substr(0,temp2.size()-1));
    temp3F = stof(temp3.substr(0,temp3.size()-1));
    if (abs(temp1F - 98.2) < 0.5) cout << temp1 << endl;
    if (abs(temp2F - 98.2) < 0.5) cout << temp2 << endl;
    if (abs(temp3F - 98.2) < 0.5) cout << temp3 << endl;
    return 0;
}
