class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string longestSubstring = "";
        string currentSubstring = "";

        int repeatingCharacters = 0;

        int index = 0;

        for (int i = index; i < s.length(); i++) {
            for (char currentSubstringCharacter : currentSubstring) {
                if (s[i] == currentSubstringCharacter) {
                    repeatingCharacters++;
                    break;
                }
            }

            if (currentSubstring.length() > longestSubstring.length()) {
                longestSubstring = currentSubstring;
            }

            if (repeatingCharacters == 1) {
                repeatingCharacters = 0;
                currentSubstring = "";
                index++;
                i = index;
            }

            currentSubstring += s[i];

        }

        if (currentSubstring.length() > longestSubstring.length()) {
            longestSubstring = currentSubstring;
        }

        return longestSubstring.length();
    }
};
