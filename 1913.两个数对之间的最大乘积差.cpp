/*
 * @lc app=leetcode.cn id=1913 lang=cpp
 *
 * [1913] 两个数对之间的最大乘积差
 */

// @lc code=start
class Solution {
public:
    // 87 6;
    // top1 >= top2 >= bot2 >= bot1
    int maxProductDifference(vector<int>& nums) {
        int top1 = INT_MIN, top2 = INT_MIN;
        int bot1 = INT_MAX, bot2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num >= top1){
                top2 = top1;
                top1 = num;
            }else if(num > top2){
                top2 = num;
            }
            if(num <= bot1){
                bot2 = bot1;
                bot1 = num;
            }else if(num < bot2){
                bot2 = num;
            }
        }
        return top1 * top2 - bot1 * bot2;
    }
};
// @lc code=end
/*
[4,4,4,4]
*/
