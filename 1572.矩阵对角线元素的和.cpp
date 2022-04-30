/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution {
public:
    // 81 57;
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int sum = 0;
        for(int i = 0; i < size; ++i){
            sum += mat[i][i];
            sum += mat[i][size-1-i];
        }
        if(size % 2 == 1){
            int center = size / 2;
            sum -= mat[center][center];
        }
        return sum;
    }
};
// @lc code=end

