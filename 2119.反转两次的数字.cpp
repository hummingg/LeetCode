/*
 * @lc app=leetcode.cn id=2119 lang=cpp
 *
 * [2119] 反转两次的数字
 */

// @lc code=start
class Solution {
    // 100 71 0 5.7;
public:
    // 能反转回去
    bool isSameAfterReversals(int num) {
        if(num == 0){
            return true;
        }
        return num % 10 != 0;
    }
};
// @lc code=end

