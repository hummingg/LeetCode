/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
    // 100 69 0 9.6;
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }else if(nums[i] > secondMax){
                secondMax = nums[i];
            }
        }
        return (firstMax - 1) * (secondMax - 1);
    }
};
// @lc code=end

