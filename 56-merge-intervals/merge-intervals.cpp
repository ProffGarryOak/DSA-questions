class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> z;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int x,y;
        x=intervals[0][0];
        y=intervals[0][1];
        for (int i=0;i<n-1;i++){
            if (intervals[i+1][0]-y>0){
                z.push_back({x,y});
                x=intervals[i+1][0];
                y=intervals[i+1][1];
            }
            y=max(y,intervals[i+1][1]);
        }
        z.push_back({x,y});
        return z;
    }
};