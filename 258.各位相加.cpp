/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    // 40 22;
    int addDigits(int num) {
        // 0: 0 (仅此一次)
        // 1: 1-9

        // 10: 1-9-1
        // 20: 2-9-1-2
        // 30: 3-9-1-3
        // 40: 4-9-1-4

        // 100: 1-9-1
        // 110: 2-9-1-2
        // 120: 3-9-1-3
        
        if(num < 10){
            return num;
        }
        int n = num % 9;
        if(n == 0){
            return 9;
        }
        return n;
    }
};
// @lc code=end

