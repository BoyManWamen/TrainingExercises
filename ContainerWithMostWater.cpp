class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = static_cast<int>(std::size(height));

        int maxArea = min(height[0],height[size-1]) * (size-1);

        int currentArea = 0;

        int i = 0;
        int j = size-1;

        while (i < j) {
            currentArea = min(height[i],height[j]) * (j-i);

            if (currentArea > maxArea) {
                maxArea = currentArea;
            }

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea;
    }
};
