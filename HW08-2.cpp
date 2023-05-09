#include<iostream>
#include<string>

char* Sandwich(std::string& line, char* bread_ptr) { 
    char *startPtr = &line[0]; 
    char* endPtr = startPtr + line.length() - 1;
    for (char* ptr = startPtr; ptr <= endPtr; ptr++) {
      char* next_ptr = ptr + 2;
      if (*ptr == *bread_ptr && *next_ptr == *bread_ptr) {
          if (ptr > startPtr && ptr < endPtr && next_ptr > startPtr && next_ptr < endPtr) {
              return ptr+1; 
          }
      }
    }
    return nullptr;
}

int main() {
    std::string line;
    char bread;
    std::getline(std::cin, line);
    std::cin >> bread;
    char* filling_ptr = Sandwich(line, &bread);
    if (filling_ptr != nullptr) {
        std::cout << *filling_ptr << std::endl; 
    }
    return 0;
}