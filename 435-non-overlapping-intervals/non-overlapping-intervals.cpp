class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 || ans.back()[1] <= intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = min(ans.back()[1], intervals[i][1]);
            }
        }
        return n - ans.size();
    }
};
