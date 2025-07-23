class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool z=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int r=0;
        for (int i=1;i<n;i++){
            if (target < matrix[i][0]){
                break;
            }
            r++;
        }
        for (int i=0;i<m;i++){
            if (target == matrix[r][i]){
                z=1;
                break;
            }
        }
    return z;
    }

};