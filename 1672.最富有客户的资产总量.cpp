/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
public:
    // 10 43;
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int maxAccount = INT_MIN;
        for(int i = 0; i < m; i++){
            int account = 0;
            for(int j = 0; j < n; j++){
                account += accounts[i][j];
            }
            if(account > maxAccount){
                maxAccount = account;
            }
        }
        return maxAccount;
    }
};
// @lc code=end

