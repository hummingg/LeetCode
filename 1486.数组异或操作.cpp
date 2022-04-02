/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
public:
    // 100 25; 
    int xorOperation(int n, int start) {
        int result = 0;
        for(int i = 0; i < n; i++){
            result ^= start;
            start += 2;
        }
        return result;
    }
};
// @lc code=end

