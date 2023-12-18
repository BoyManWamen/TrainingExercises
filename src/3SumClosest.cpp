class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestThreeSum = nums[0]+nums[1]+nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size()-1;

            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (currentSum == target) {
                    return currentSum;
                } else {
                    if (currentSum < target) {
                        j++;
                    } else {
                        k--;
                    }
                }

                if (abs(currentSum-target) < abs(closestThreeSum-target)) {
                    closestThreeSum = currentSum;
                }

            }
        }

        return closestThreeSum;
    }
};
