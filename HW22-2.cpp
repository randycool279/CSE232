#include "HW20-2.hpp"

Counter::Counter(int initialValue) : currentValue(initialValue) {
    appendToLog("Constructor called with a " + std::to_string(initialValue));
}

int Counter::Value() {
    appendToLog("Value called. Returned a " + std::to_string(currentValue));
    return currentValue--;
}

std::ostream &operator<<(std::ostream &os, const Counter &counter) {
    counter.appendToLog("<< called.");
    os << "Counter(" << counter.currentValue + 1 << ")@" << counter.currentValue;
    return os;
}

Counter operator+(const Counter &lhs, const Counter &rhs) {
    Counter newCounter(lhs.currentValue + rhs.currentValue + 2);
    newCounter.appendToLog("+ called.");
    return newCounter;
}

void Counter::appendToLog(const std::string &message) const {
    const_cast<std::vector<std::string>&>(log_).emplace_back(message);
}
