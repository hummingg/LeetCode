/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i+2] = max(dp[i] + nums[i+2] , dp[i+1])
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }

        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        // memset(dp, 0, sizeof(dp)); // 0 or -1
        for(int i = 2; i < size; ++i){
            // int m = max(dp[i-2] + nums[i] , dp[i-1]);
            // if(m == dp[i-1]){
            //     cout << false << endl;
            // }else{
            //     cout << true << endl;
            // }
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);   // 不偷 vs 偷
        }
        return dp[size-1];
    }

    // 100 90;
    int rob1(vector<int>& nums) {
        // dp[i+2] = max(dp[i] + nums[i+2] , dp[i+1])
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }else if(size == 2){
            return max(nums[0], nums[1]);
        }else if(size == 3){
            return max(nums[0]+nums[2], nums[1]);
        }

        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = max(nums[0] + nums[2], nums[1]);
        // memset(dp, 0, sizeof(dp)); // 0 or -1
        for(int i = 3; i < size; ++i){
            dp[i] = max({dp[i-3] + nums[i], dp[i-2] + nums[i], dp[i-1]});
        }
        // return max(dp[size-2], dp[size-1]);
        return dp[size-1];
    }
};
// @lc code=end
/*
1 表示盗窃
1010    dp[i-1]
1001    dp[i-3] + nums[i]
0101    dp[i-2] + nums[i]


[1,2,3,1]\n
[2,7,9,3,1]\n
[0]\n
[2,1,1,2]
*/
