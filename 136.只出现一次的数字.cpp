/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c = 0;  // 不默认为0
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            c ^= nums[i];
        }
        return c;
    }
};
// @lc code=end

