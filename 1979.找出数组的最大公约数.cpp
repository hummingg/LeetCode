/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start
class Solution {
    // 43 26;
public:
    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN, minNum = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        for(int i = minNum; i>1; --i){
            if(minNum % i == 0 && maxNum % i == 0){
                return i;
            }
        }
        return 1;
    }
};
// @lc code=end

