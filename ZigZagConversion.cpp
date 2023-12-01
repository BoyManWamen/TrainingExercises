class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 1) {
            return s;
        }
        
        string answer = "";

        vector<string> stringVectors(numRows);

        int row = 0;
        int rowDirection = -1;

        for (int i = 0; i < s.length(); i++) {
            if (row == (numRows-1) || row == 0) {
                rowDirection *= -1;
            }

            stringVectors[row] += s[i];

            if (rowDirection == 1) {
                row++;
            } else {
                row--;
            }
        }

        for (auto& stringVector : stringVectors) {
            answer += stringVector;
        }

        return answer;
    }
};
