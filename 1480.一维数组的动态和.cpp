/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v;
        int sum = 0;
        for(auto n : nums){
            sum += n;
            v.push_back(sum);
        }
        return v;
    }
};
// @lc code=end

