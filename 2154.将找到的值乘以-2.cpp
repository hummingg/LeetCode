/*
 * @lc app=leetcode.cn id=2154 lang=cpp
 *
 * [2154] 将找到的值乘以 2
 */

// @lc code=start
class Solution {
    // 95 46 4 10.3;
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(original == nums[i]){
                original *= 2;
            }else if(original < nums[i]){
                break;
            }
        }
        return original;
    }
};
// @lc code=end

