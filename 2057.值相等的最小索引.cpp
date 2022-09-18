/*
 * @lc app=leetcode.cn id=2057 lang=cpp
 *
 * [2057] 值相等的最小索引
 */

// @lc code=start
class Solution {
    // 98 99 4 21.2;
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(i % 10 == nums[i]){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

