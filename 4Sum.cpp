class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> allSums;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int m = j+1;
                int k = nums.size() - 1;

                while (m < k) {
                    long long int sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[m]+(long long)nums[k];

                    vector<int> sums = {nums[i],nums[j],nums[m],nums[k]};

                    if (sum == target) {
                        allSums.push_back(sums);
                    }

                    if (sum < target) {
                        m++;
                    } else {
                        k--;
                    }

                }
            }
        }

        sort(allSums.begin(),allSums.end());

        allSums.erase(std::unique(allSums.begin(), allSums.end()), allSums.end());

        return allSums;
    }
};
