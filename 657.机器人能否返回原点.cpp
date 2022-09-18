/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
    // 86 14;
public:
    bool judgeCircle(string moves) {
        int right = 0, up = 0;
        int size = moves.size();
        for(int i = 0; i < size; ++i){
            switch (moves[i])
            {
            case 'R':
                ++right;
                break;
            case 'L':
                --right;
                break;
            case 'U':
                ++up;
                break;
            case 'D':
                --up;
                break;
            default:
                break;
            }
        }
        return right == 0 && up == 0;
    }
};
// @lc code=end

