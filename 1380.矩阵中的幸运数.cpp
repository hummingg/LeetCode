/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
    // 59 95 20 11;
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> minRow(m);
        for(int i = 0; i < m; ++i){
            int minNum = INT_MAX;
            for(int j = 0; j < n; ++j){
                if(minNum > matrix[i][j]){
                    minRow[i] = j;
                    minNum = matrix[i][j];
                }
            }
        }

        vector<int> ret;
        for(int i = 0; i < m; ++i){
            int col = minRow[i];
            bool erased = false;
            for(int j = 0; j < m; ++j){
                if(matrix[j][col] > matrix[i][col]){
                    erased = true;
                    break;
                }
            }
            if(!erased){
                ret.push_back(matrix[i][col]); 
            }
        }
        return ret;
    }
};
// @lc code=end

