/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
    // 33 66;
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i+=2){
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end
/*
[1,4,3,2]
[6,2,6,5,1,2]
*/
