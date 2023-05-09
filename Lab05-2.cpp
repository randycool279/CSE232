#include <iostream>
#include <string>
#include <map>

const int max_letter = 17;

// convert a location letter to its decimal value
int loc_to_dec(char loc)
{
    int power = 1;
    for (char i = 'a'; i <= 'g'; i++)
    {
        if (loc == i)
        {
            return power;
        }
        power *= 2;
    }
    return 0;
}

// convert a decimal value to a location letter
char dec_to_loc(int dec)
{
    for (char i = 'a'; i <= 'g'; i++)
    {
        if (dec == loc_to_dec(i))
        {
            return i;
        }
    }
    return 0;
}

// convert a location arithmetic string to decimal
std::int64_t LocToDec(std::string const & loc)
{
    std::int64_t dec = 0;
    for (char c : loc)
    {
        dec += loc_to_dec(c);
    }
    return dec;
}

// simplify a location arithmetic string to its abbreviated form
std::string Abbreviate(std::string const & loc)
{
    std::string result = loc;
    int index = 0;
    while (index < result.length() - 1)
    {
        int power = loc_to_dec(result[index]);
        int next_power = loc_to_dec(result[index + 1]);
        if (power < next_power)
        {
            result[index] = dec_to_loc(power + next_power);
            result.erase(index + 1, 1);
        }
        else
        {
            index++;
        }
    }
    return result;
}

// convert decimal to abbreviated location arithmetic string
std::string DecToLoc(std::int64_t dec)
{
    std::string result;
    int power = max_letter;
    while (dec > 0)
    {
        while (loc_to_dec(dec_to_loc(power)) > dec)
        {
            power /= 2;
        }
        result += dec_to_loc(power);
        dec -= power;
    }
    return result;
}

// add two location arithmetic strings and return the result
std::int64_t AddLoc(std::string const & loc1, std::string const & loc2)
{
    std::string concat = loc1 + loc2;
    std::string abbreviated = Abbreviate(concat);
    return LocToDec(abbreviated);
}

int main() {
  std::string loc1, loc2;
  int64_t dec;
  
  std::cout << "Give me a location string:\n";
  std::cin >> loc1;
  
  std::cout << "Give me an integer:\n";
  std::cin >> dec;
  
  std::cout << loc1 << " to dec: " << LocToDec(loc1) << std::endl;
  std::cout << loc1 << " abbreviated: " << Abbreviate(loc1) << std::endl;
  std::cout << dec << " to loc: " << DecToLoc(dec) << std::endl;
  
  std::cout << "Give me two more location strings:\n";
  std::cin >> loc1 >> loc2;
  
  std::cout << "Sum of " << loc1 << " and " << loc2 << " is: " << AddLoc(loc1, loc2) << std::endl;
  
  return 0;
}


