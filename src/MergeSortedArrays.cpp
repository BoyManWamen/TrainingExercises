class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int newSize = m + n;

        int count = 0;

        for (int i = m; i < newSize; i++) {
            nums1[i] = nums2[count++];
        }

        sort(nums1.begin(),nums1.end());
    }
};
