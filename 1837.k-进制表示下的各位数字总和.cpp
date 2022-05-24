/*
 * @lc app=leetcode.cn id=1837 lang=cpp
 *
 * [1837] K 进制表示下的各位数字总和
 */

// @lc code=start
class Solution {
    // 100 6;
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while(n >= k){
            sum += n % k;
            n /= k;
        }
        sum += n;
        return sum;
    }
};
// @lc code=end

