/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    // 100 85;
    // 动态规划
    int countVowelStrings(int n) {
        int dp[n+1][6];   // 0占位。 5 个不同字符能组成的长度为 n 的字典序字符串的个数
        for(int i=0; i < n+1; i++){
            for(int j=0; j < 6; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i < n+1; i++){
            dp[i][1] = 1;
        }
        for(int i=1; i < 5+1; i++){
            dp[1][i] = i;
        }
        for(int i=2; i<n+1; i++){
            for(int j=2; j<6;j++){
                int m = j;
                while(m>0){
                    dp[i][j] += dp[i-1][m--];
                }
            }
        }

        return dp[n][5];
    }
};
// @lc code=end

