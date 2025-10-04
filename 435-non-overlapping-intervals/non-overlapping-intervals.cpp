class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by start time
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int count = 1;                 // first interval always counted
        int prevEnd = intervals[0][1]; // track end of last non-overlapping interval

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prevEnd) {
                // No overlap — keep this interval
                count++;
                prevEnd = intervals[i][1];
            } else {
                // Overlap — keep the one with smaller end time
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }

        return n - count; // number of intervals removed
    }
};
