#include <iostream>
#include <string>
#include <vector>

bool AtListPosition(const std::string& word_list, const std::string& word, size_t pos) {
  if (pos + word.length() > word_list.length()) {
    return false; 
  }
  if (pos > 0 && word_list[pos - 1] != ',') {
    return false; 
  }
  if (word_list.compare(pos, word.length(), word) != 0) {
    return false; 
  }
  if (pos + word.length() < word_list.length() && word_list[pos + word.length()] != ',') {
    return false; 
  }
  return true;
}


size_t FindInList(const std::string& wordList, const std::string& word, size_t startPos = 0) {
    size_t pos = wordList.find(word, startPos);
    while (pos != std::string::npos) {
        if (AtListPosition(wordList, word, pos)) {
            return pos;
        }
        pos = wordList.find(word, pos + 1);
    }
    return std::string::npos;
}

std::string GetFirstInList(const std::string& word_list, std::string* word1_ptr,
                           std::string* word2_ptr) {
  size_t pos1 = FindInList(word_list, *word1_ptr);
  size_t pos2 = FindInList(word_list, *word2_ptr);
  if (pos1 == std::string::npos && pos2 == std::string::npos) {
    return "N/A";
  } else if (pos1 < pos2) {
    return *word1_ptr;
  } else {
    return *word2_ptr;
  }
}


size_t CountInList(const std::string& wordList, const std::string& word) {
    int count = 0;
    size_t pos = 0;
    while ((pos = FindInList(wordList, word, pos)) != std::string::npos) {
        count++;
        pos += word.length();
    }
    return count;
}
int main() {
    std::string keyword1, keyword2;
    std::cin >> keyword1 >> keyword2;

    std::string line;
    while (getline(std::cin, line)) {
      
        if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
            //https://www.geeksforgeeks.org/stdstringfind_first_not_of-in-c/
            //Used to skip any lines that are blank or contain only whitespace characters
            //'" \t\n\v\f\r"' are collectively known as whitespace characters 
            //because they are used to represent horizontal or vertical space between words or lines in text
            
            continue;
        }

        
        std::vector<std::string> words;
        //https://iq.opengenus.org/extract-integers-from-string-in-cpp/
		    //https://cplusplus.com/forum/beginner/99171/
		    //I learned how to extract words from a list using vectors and its function 
		    //push_back() which allows me to append values to the vector
        size_t pos = 0;
        while (pos < line.length()) {
            size_t endPos = line.find(',', pos);
            if (endPos == std::string::npos) {
                endPos = line.length();
            }
            words.push_back(line.substr(pos, endPos - pos));
            pos = endPos + 1;
        }

        int count1 = 0;
        int count2 = 0;
        for (const std::string& word : words) {
            if (!word.empty()) {
                if (AtListPosition(word, keyword1, 0)) {
                    count1 += CountInList(word, keyword1);
                } else if (AtListPosition(word, keyword2, 0)) {
                    count2 += CountInList(word, keyword2);
                }
            }
        }

        std::string first = GetFirstInList(line, &keyword1, &keyword2);
        if (first == "N/A") {
            count1 = 0;
            count2 = 0;
        }
        std::cout << first << ' ' << count1 << ' ' << count2 << '\n';
    }

    return 0;
}




