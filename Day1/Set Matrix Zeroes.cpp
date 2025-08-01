// Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/
//
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0&#39;s.
// 
// You must do it in place.
// 
// &nbsp;
// Example 1:
// 
// 
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// 
// 
// Example 2:
// 
// 
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// 
// 
// &nbsp;
// Constraints:
// 
// 
// 	m == matrix.length
// 	n == matrix[0].length
// 	1 &lt;= m, n &lt;= 200
// 	-231 &lt;= matrix[i][j] &lt;= 231 - 1
// 
// 
// &nbsp;
// Follow up:
// 
// 
// 	A straightforward solution using O(mn) space is probably a bad idea.
// 	A simple improvement uses O(m + n) space, but still not the best solution.
// 	Could you devise a constant space solution?

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         set<int> zr,zc;
//         int m=matrix.size();
//         int n=matrix[0].size();
//         for (int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if (matrix[i][j]==0){
//                     zr.insert(i);
//                     zc.insert(j);
//                 }
//             }
//         }
        
//         for (int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if (zr.count(i) || zc.count(j)) {
//                     matrix[i][j]=0;
//                 }
//                 }
//             }
        
//     }
// };


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
