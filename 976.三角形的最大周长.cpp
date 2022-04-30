/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution {
public:
    // 9 71;
    int largestPerimeter(vector<int>& nums) {
        // 两边之和大于第三边，小1+小2>大
        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i >= 2 ; --i){
            if(nums[i] < nums[i-1] + nums[i-2]){
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }
};
// @lc code=end

