#include "functions.hpp"
std::vector<std::string> split(std::string const &s, char sep) {
    std::vector<std::string> result;
    std::string item;
    size_t start = 0, end = 0;
    while ((end = s.find(sep, start)) != std::string::npos) {
        item = s.substr(start, end - start);
        result.push_back(item);
        start = end + 1;
    }
    item = s.substr(start);
    result.push_back(item);

    if (!result.empty() && result.back().empty()) {
        result.pop_back();
    }
    
    return result;
}
void print_vector(ostream &out, vector<string> const &v) {
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
        out << *it << " ";
    }
}
