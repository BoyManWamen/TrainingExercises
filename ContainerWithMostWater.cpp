class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = static_cast<int>(std::size(height));

        int area = min(height[0],height[size-1]) * (size-1);

        int index = size;

        int currentArea;

        for (int i = 0; i < size; i++) {
            for (int j = size-1; j >= 0; j--) {
                
                currentArea = min(height[i],height[j]) * (j-i);


                if (currentArea > area) {
                    area = currentArea;
                }
            }
        }

        return area;
    }
};
