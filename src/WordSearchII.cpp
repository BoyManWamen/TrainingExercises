class Solution {
public:
    unordered_map<string, int> wordMap;

    void solveWord(vector<vector<char>>& board, string temp, int i, int j, vector<string>& answer, unordered_map<string, int>& prefixes) {
        if (prefixes.find(temp) == prefixes.end()) {
            return;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size()) {
            return;
        }

        char usedCell = board[i][j];
        board[i][j] = '*';

        if (wordMap.find(temp) != wordMap.end()) {
            answer.push_back(temp);
            wordMap.erase(temp);
        }

        if (i - 1 >= 0 && board[i - 1][j] != '*') {
            solveWord(board, temp+board[i - 1][j], i-1, j, answer, prefixes);
        }

        if (i + 1 < board.size() && board[i + 1][j] != '*') {
            solveWord(board, temp+board[i + 1][j], i+1, j, answer, prefixes);
        }

        if (j - 1 >= 0 && board[i][j - 1] != '*') {
            solveWord(board, temp+board[i][j - 1], i, j-1, answer, prefixes);
        }

        if (j + 1 < board[i].size() && board[i][j + 1] != '*') {
            solveWord(board, temp+board[i][j + 1], i, j+1, answer, prefixes);
        }

        board[i][j] = usedCell;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]]++;
        }

        vector<string> answer;

        unordered_map<string, int> prefixes;

        for (int i = 0; i < words.size(); i++) {
            string temp = "";

            for (int j = 0; j < words[i].size(); j++) {
                temp += words[i][j];
                prefixes[temp] = 1;
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (wordMap.size() == 0) {
                    return answer;
                }

                string temp = "";
                
                temp += board[i][j];
                solveWord(board, temp, i, j, answer, prefixes);
            }
        }
 
        return answer;
    }
};
