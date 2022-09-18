/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
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
        for(int i = 0; i < size; ++i){
            nums[i] = c ^ nums[i];
        }
        for(int i = 0; i < size; ++i){
            c ^= nums[i];
        }
        return c;
    }
};
// @lc code=end

