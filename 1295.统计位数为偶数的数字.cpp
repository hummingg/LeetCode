/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
    // 92 70;
public:
    int findNumbers(vector<int>& nums) {
        // 2： 10^1 10~99 10^2 4：1000~9999
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if((int)(log2(nums[i])/log2(10)) % 2 == 1){
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

