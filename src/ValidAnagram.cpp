#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charMap;

        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (charMap[t[i]] >= 1) {
                charMap[t[i]]--;
            } else {
                return false;
            }
        }

        if (t.length() == s.length()) {
            return true;
        }

        return false;
    }
};
