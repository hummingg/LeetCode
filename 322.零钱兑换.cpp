/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int count = 0;
        for(int i = coins.size()-1; i >= 0; --i){
            if(amount > coins[i]){
                count += amount/ coins[i];
            }
        }
    }
};
// @lc code=end

