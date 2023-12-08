class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      sort(strs.begin(), strs.end());

      string longestPrefix = "";

      string firstWord = strs[0], lastWord = strs[strs.size() - 1];

      for (int i = 0; i < firstWord.length() && i < lastWord.length(); i++) {
          if (firstWord[i] == lastWord[i]) {
              longestPrefix += firstWord[i];
          } else {
            break;
          }
      }

      return longestPrefix;
    }
};
