class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        vector<vector<int>> mergedIntervals;

        sort(intervals.begin(), intervals.end());

        vector<int> newMerge = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= newMerge[1] && intervals[i][1] >= newMerge[1]) {
                newMerge[1] = intervals[i][1];
            } else if (newMerge[1] > intervals[i][0] && newMerge[1] > intervals[i][1]) {
                continue;
            } else {
                mergedIntervals.push_back(newMerge);
                newMerge.clear();
                newMerge = intervals[i];
            }
        }

        mergedIntervals.push_back(newMerge);

        return mergedIntervals;
    }
};
