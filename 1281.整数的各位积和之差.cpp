/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    // 100 22; 100 80; 100 68; 100 16;
    int subtractProductAndSum(int n) {
        int sum = 0, mul = 1;
        do{
            int low = n % 10;
            sum += low;
            mul *= low;
            n /= 10;
        }while(n > 0);
        return mul - sum;
    }
};
// @lc code=end

