/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back(nums[nums[i]]);
        }
        return v;
    }
};
// @lc code=end

