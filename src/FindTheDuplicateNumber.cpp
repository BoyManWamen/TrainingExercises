#include <map>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> integerMap;

        for (auto i : nums) {
            integerMap[i]++;
        }

        int answer;

        for (auto i : integerMap) {
            if (i.second > 1) {
                answer = i.first;
            }
        }

        return answer;
    }
};
