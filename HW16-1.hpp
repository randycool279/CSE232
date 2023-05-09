#ifndef CENSOR_H
#define CENSOR_H

#include <iostream>
#include <map>
#include <string>
#include <set>

std::set<std::string> ReplacementCensor(std::istream& input, std::ostream& output, std::map<std::string, std::string> replaceWords);

#endif /* CENSOR_H */