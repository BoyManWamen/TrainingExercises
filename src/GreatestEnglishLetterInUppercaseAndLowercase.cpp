#include <unordered_set>

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> lowerCaseFound;
        string answer = "";
        char temporary = ' ';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lowerCaseFound.insert(s[i]);
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                if (lowerCaseFound.find(s[i] + 32) != lowerCaseFound.end()) {
                    temporary = max(temporary, s[i]);
                }
            }
        }

        if (temporary != ' ') {
            answer += temporary;
        }

        return answer;
    }   
};
