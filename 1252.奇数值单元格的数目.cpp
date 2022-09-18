/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution {
    // 71 58 4 7.6;
public:
    // 进阶？
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0), cols(n, 0);
        for(int i = 0; i < indices.size(); ++i){
            ++rows[indices[i][0]];
            ++cols[indices[i][1]];
        }
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int num = rows[i] + cols[j];
                if(num % 2 == 1){
                    ++count;
                }
            }
        }
        return count;
    }
};
// @lc code=end

