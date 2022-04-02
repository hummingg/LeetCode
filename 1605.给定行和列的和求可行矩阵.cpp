/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
class Solution {
public:
    // 48 88;
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> ret(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols && rowSum[i] > 0; ++j){
                ret[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ret[i][j];
                colSum[j] -= ret[i][j];
            }
        }
        return ret;
    }
};
// @lc code=end
