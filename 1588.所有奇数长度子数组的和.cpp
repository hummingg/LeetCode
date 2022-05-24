/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // 5个元素。0：
    }
};
// @lc code=end
/*
长为 1 的和长为 n  的
     3         n-2
 n 个元素，奇数长度有1、3、、n或n-1。假设n是奇数。
      奇    偶
0: 1->n     n-1     n/2+1
1: 1->n-2   n-1     (n-2)/2+1
2: 1->n-2   n-3     (n-2)/2+1
3: 1->n-4   n-3     (n-4)/2+1
4: 1->n-4   n-5     (n-4)/2+1
n-4: 1->3
n-3: 1->3
n-2: 1      1
n-1: 1      1

长为 n，奇数为m的连续子字符串有n-m+1个
1,2,3,...,m[m-1],...,m[n-m],m-1[n-m+1],...,3,2,1
*/
