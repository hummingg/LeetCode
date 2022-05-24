/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
class Solution {
public:
    // 100 18; 100 77;
    int countOdds(int low, int high) {
        // 共 high - low + 1 个数
        if(low % 2 == 0){   // 偶数开头
            return (high - low + 1)/2;
        }
        return 1 + (high - low)/2;  // 奇数开头
    }
};
// @lc code=end

