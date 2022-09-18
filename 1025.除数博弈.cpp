/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int n) {
        // n = kx, n-x=(k-1)x.
        // 结果 己方拿到的数
        // 赢：2 4 6 8 10
        // 输：1 3 5 7 9 11

        // 奇数 = 奇数 * 奇数：
        // 奇数-奇数=偶数，新数必然是偶数。
        // 己方拿到奇数，然后对方拿到偶数，对方赢。

        // 偶数 = 奇数 * 偶数 or 偶数 * 偶数
        // 尽量给对方奇数，偶数-奇数=奇数，新数是奇数。
        // 己方拿到偶数，然后对方拿到奇数，己方赢。

        return n % 2 == 0;
    }
};
// @lc code=end

