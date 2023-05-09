#ifndef COUNTER_HEADER_HPP
#define COUNTER_HEADER_HPP

#include <vector>
#include <string>
#include <iostream>

class Counter {
public:
    Counter(int initialValue);
    int Value();

    std::vector<std::string> log_;

    friend std::ostream &operator<<(std::ostream &os, const Counter &counter);
    friend Counter operator+(const Counter &lhs, const Counter &rhs);

private:
    int currentValue;
    void appendToLog(const std::string &message) const;
};

#endif // COUNTER_HEADER_HPP
