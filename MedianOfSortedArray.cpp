class Solution {
public:
    void bubbleSort(vector<int>& array) {
        const int length = static_cast<int>(std::size(array));

        int swapCounter = 0;

        for (int j = 0; j < length - 1; j++) {
            swapCounter = 0;

            int endOfArray = length - j;

            for (int index = 0; index < endOfArray - 1; index++) {
                if (array[index] > array[index + 1]) {
                    int temp = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = temp;
                    swapCounter++;
                }
            }

            if (swapCounter == 0) {
                break;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int length1 = static_cast<int>(std::size(nums1));
        const int length2 = static_cast<int>(std::size(nums2));

        vector<int> mergedArray = {};
        for (int i = 0; i < length1; i++) {
            mergedArray.push_back(nums1[i]);
        }

        for (int i = 0; i < length2; i++) {
            mergedArray.push_back(nums2[i]);
        }

        bubbleSort(mergedArray);

        double median = 0;

        int length = static_cast<int>(std::size(mergedArray));

        if ((length) % 2 == 0) {
            median += mergedArray[(length/2)-1];
            median += mergedArray[(length/2)];

            median = median / 2;
        } else {
            median += mergedArray[(length/2)];
        }

        return median;
    }
};
