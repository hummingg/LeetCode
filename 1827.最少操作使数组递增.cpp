/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution {
    // 70 71;
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return 0;
        }
        int count = 0;
        for(int i = 1; i < size; ++i){
            if(nums[i] <= nums[i-1]){
                count += nums[i-1]+1-nums[i];
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }
};
// @lc code=end

