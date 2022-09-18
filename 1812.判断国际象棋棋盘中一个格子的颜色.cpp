/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
class Solution {
    // 100 24;
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a';
        int row = coordinates[1] - '1';
        return abs(row-col) % 2 == 1;
    }
};
// @lc code=end

