class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool frz = false, fcz = false;

        int m=matrix.size();
        int n=matrix[0].size();
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                frz = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                fcz = true;
        }

        
        for (int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if (matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for (int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if (matrix[0][j] ==0 || matrix[i][0]==0) {
                    matrix[i][j]=0;
                }
                }
            }
        if(frz){
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        }
        if (fcz){
            for (int j = 0; j < m; j++)
                matrix[j][0] = 0;

        }
        
    }
};
