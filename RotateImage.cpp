class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = static_cast<int>(std::size(matrix));

        for (int i = 0; i < length; i++) {
            for (int d = 0; d <= i; d++) {
                swap(matrix[i][d], matrix[d][i]);
            }
        }

        for (int i = 0; i < length; i++) {
            reverse((matrix[i]).begin(), matrix[i].end());
        }
    }
};
