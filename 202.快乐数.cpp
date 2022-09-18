/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    // 难
    bool isHappy(int n) {
        // m2+n2=10m+n
        cout << (unsigned int)(1 << 31)  -1 << endl;
        return false;
    }
};
// @lc code=end
/*
10 * 9^2 = 810 最多得到3位数
3 * 9^2 = 243 仅 1 10 100 可能
1 = 1^2 + 0^2
10 = 1^2 + 3^2
100 = 
1 4 9 16 25 36 49 64 81
*/
