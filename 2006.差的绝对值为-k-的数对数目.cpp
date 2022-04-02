/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
class Solution {
public:
    // 71 90;
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int num_1 = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(abs(num_1 - nums[j]) == k){
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

