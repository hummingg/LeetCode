/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start
class Solution {
public:
    // 100 5;
    int countNumbersWithUniqueDigits(int n) {
        // 0-9 排列2个数
        if(n <= 1){
            return pow(10, n);
        }
        int preMul = 9;
        vector<int> v;
        v.push_back(preMul);
        for(int j = 0; j < 7; ++j){
            preMul *= 9 - j;
            v.push_back(preMul);
        }
        int count = 10; // 1位的
        for(int i = 2; i <= n; ++i){
            count += v[i-1];
        }
        return count;
    }

    // 100 10;
    // 少于 n 位的数
    int countNumbersWithUniqueDigits1(int n) {
        // 0-9 排列2个数
        // A_10_1=10 A_10_2-9(00)=81
        if(n <= 1){
            return pow(10, n);
        }
        int count = 10; // 1位的
        for(int i = 2; i <= n; ++i){
            int mul = 9; // 非 0 开头
            for(int j = 0; j < i-1; ++j){
                mul *= 9 - j;
            }
            count += mul;
        }
        return count;
    }
};
// @lc code=end

