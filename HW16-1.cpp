#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include "HW16-1.hpp"

std::set<std::string> ReplacementCensor(std::istream& input, std::ostream& output, std::map<std::string, std::string> replaceWords)
{
    std::set<std::string> replacedWords;
    std::string line;
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word)
        {
            std::string lower_word;
            for (char c : word)
            {
                lower_word += tolower(c);
            }

            auto iterate = replaceWords.find(lower_word);
            if (iterate != replaceWords.end())
            {
                replacedWords.insert(word);
                word = iterate->second;
            }
            output << word << " ";
        }
        output << std::endl;
    }
    return replacedWords;
}
