#ifndef INDICIES_HEADER
#define INDICIES_HEADER

#include <vector>
#include <stdexcept>

class PythonicIntVector {
    std::vector<int> vec;

public:
    void push_back(int value);
    int at(int index) const;
    int& at(int index);
};

#endif // INDICIES_HEADER