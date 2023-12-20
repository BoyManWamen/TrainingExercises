#include <string>
#include <unordered_map>

std::unordered_map<char,int> charCount(std::string inputString) {
  std::unordered_map<char,int> returnMap;
  
  for (char ch : inputString) {
    returnMap[ch] += 1;
  }
  
  return returnMap;
}

bool anagrams(std::string s1, std::string s2) {
  return charCount(s1) == charCount(s2);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
