/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    // 85 29;
    vector<int> countBits0(int n) {
        if(n == 0){
            return {0};
        }
        if(n == 1){
            return {0, 1};
        }
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        int i = 2;
        while(i <= n){  // i = 2
            int loga = (int)log2(i);    // 1
            int expoBegin = pow(2, loga);   // 2
            int half = expoBegin / 2;    // 1
            int expoEnd = expoBegin + half;    // 3
            while(i <= n && i < expoEnd){
                ans[i] = ans[i-half];
                ++i;
            }

            expoBegin = expoEnd;    // 3
            expoEnd = 4 * half;  // 4
            while(i <= n && i < expoEnd){
                ans[i] = ans[i-2*half] + 1;
                ++i;
            }
        }
        return ans;
    }

    // 23 28;
    vector<int> countBits(int n) {
        if(n == 0){
            return {0};
        }
        if(n == 1){
            return {0, 1};
        }
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 2; i <= n; ++i){
            int loga = (int)log2(i);    // 重复计算太多次
            int expo = pow(2, loga-1);
            if(i < pow(2, loga) + expo){
                ans[i] = ans[i-expo];
            }else{
                ans[i] = ans[i-2*expo] + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
/*
(int)log2(n)=3 2^(3-1)+(n-2^(3-1)) + ()
8=4 9=5 10=6 11=7 [12]=4+'1 ... 15=7+'1
0  1     10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111
(0) (1)  (1 2) (1   2。   2   3)   (1    2     2   3。  2     3    3    4)
*/
