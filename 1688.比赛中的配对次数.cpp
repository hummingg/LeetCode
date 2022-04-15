/*
 * @lc app=leetcode.cn id=1688 lang=cpp
 *
 * [1688] 比赛中的配对次数
 */

// @lc code=start
class Solution {
public:
    // 100 11;
    int numberOfMatches(int n) {
        int ret = 0;
        while(n > 1){
            ret += n/2;
            if(n % 2 == 1){
                n = (n-1) / 2 + 1;
            }else{
                n = n / 2;
            }
        }
        return ret;
    }
};
// @lc code=end

