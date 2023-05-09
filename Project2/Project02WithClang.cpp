#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool OpenFile(const std::string& filename,
              std::ifstream& file) {  // As recommended by profs, passed
                                      // filestream by reference
  file.open(filename);
  return file.is_open();
}

bool ReadEncodingPairs(std::unordered_map<char, char>& encoding_map) {
  std::string input;
  while (std::cin >> input &&
         input != "q") {  // read input and pass to encoding_map
    if (input.length() != 2) {
      std::cerr << "Error: Incorrect/Unknown encoding '" << input << "'.\n";
      return false;
    }
    char first_second = input.at(0),
         to = input.at(1);  // extract first and second characters using at
                            // method, as recommended by profs
    if (encoding_map.find(first_second) != encoding_map.end()) {
      std::cerr << "Error: The character '" << first_second
                << "' is encoded as both '" << encoding_map.at(first_second)
                << "' and '" << to << "'.\n";
      return false;
    }
    encoding_map.insert({first_second, to});
  }
  return true;
}

std::string ApplyEncoding(const std::string& line,
                          const std::unordered_map<char, char>& encoding_map) {
  std::string applied_encoding(line);
  for (char& x :
       applied_encoding) {  // Loop through each char in the string and apply
                            // encoding map if the character exists in it
    auto it = encoding_map.find(x);
    if (it != encoding_map.end()) {
      x = it->second;
    }
  }
  return applied_encoding;
}

void ProcessFile(std::ifstream& file,
                 const std::unordered_map<char, char>& encoding_map) {
  std::unordered_set<std::string>
      encoded_lines;  // Initialized to store unique encoded lines
  std::string line;
  while (std::getline(file, line)) {
    std::string encoded = ApplyEncoding(line, encoding_map);
    if (encoded_lines.find(encoded) ==
        encoded_lines.end()) {  // Check if the current encoded line is already
                                // in the set of unique encoded lines
      std::cout << encoded << std::endl;
      encoded_lines.insert(encoded);  // Add the unique encoded line to the set
    }
  }
}

int main() {
  std::string filename;
  std::cin >> filename;

  std::ifstream file;
  if (!OpenFile(filename, file)) {
    std::cerr << "Error: Cannot open '" << filename << "'.\n";
    return 1;
  }

  std::unordered_map<char, char> encodingMap;
  if (!ReadEncodingPairs(encodingMap)) {
    return 1;
  }

  ProcessFile(file, encodingMap);
  return 0;
}
