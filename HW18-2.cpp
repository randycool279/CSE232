#include "HW18-2.hpp"

int PythonicIntVector::at(int index) const {
    if (index < 0) {
        index = vec.size() + index;
    }

    if (index < 0 || index >= static_cast<int>(vec.size())) {
        throw std::out_of_range("out of range");
    }

    return vec.at(index);
}

int& PythonicIntVector::at(int index){
    if (index < 0) {
        index = vec.size() + index;
    }

    if (index < 0 || index >= static_cast<int>(vec.size())) {
        throw std::out_of_range("out of range");
    }

    return vec.at(index);
}

void PythonicIntVector::push_back(int value) {
    vec.push_back(value);
}