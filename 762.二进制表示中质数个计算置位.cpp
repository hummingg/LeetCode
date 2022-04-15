/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    // 65 33;
    int countPrimeSetBits(int left, int right) {
        // 10 6 2 20
        // 2 3 5 7 11 13 17 19
        int count = 0;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        for(int i = left; i <= right; ++i){
            if(find(primes.begin(), primes.end(), __builtin_popcount(i)) != primes.end()){
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

