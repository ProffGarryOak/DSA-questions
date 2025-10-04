class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int z = 1;
        int lastInterval = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        for (int currentInterval = 1; currentInterval < n; currentInterval++) {
            if (intervals[currentInterval][0] >= intervals[lastInterval][1]) {
                lastInterval = currentInterval;
                z++;
            }
        }
        return n - z;
    }
};