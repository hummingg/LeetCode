using System;
/*
 * @lc app=leetcode.cn id=926 lang=csharp
 *
 * [926] 将字符串翻转到单调递增
 *
 * https://leetcode.cn/problems/flip-string-to-monotone-increasing/description/
 *
 * algorithms
 * Medium (55.85%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 19K
 * Testcase Example:  '"00110"'
 *
 * 如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。
 * 
 * 给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。
 * 
 * 返回使 s 单调递增的最小翻转次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "00110"
 * 输出：1
 * 解释：翻转最后一位得到 00111.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "010110"
 * 输出：2
 * 解释：翻转得到 011111，或者是 000111。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "00011000"
 * 输出：2
 * 解释：翻转得到 00000000。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 43 14;
    public int MinFlipsMonoIncr(string s) {
        int size = s.Length;
        var left = new int[size+2];     // 前后各填充1个位置
        var right = new int[size+2];    // 前后各填充1个位置
        // 程序局部性原理，使用 2 个for
        for(int i = 0; i < size; ++i){
            left[i+1] = left[i] + (s[i] == '1' ? 1 : 0);
        }
        for(int i = size - 1; i >= 0 ; --i){
            right[i+1] = right[i+2] + (s[i] == '0' ? 1 : 0);
        }
        int ret = int.MaxValue;
        for(int i = 0; i < size; ++i){
            // 以s[i]为界，左边的1变0，右边的0变1。s[i]可0可1，所以不用变。
            ret = Math.Min(ret, left[i] + right[i+2]);
        }
        return ret;
    }
}
// @lc code=end
/*
'"00110"\n
"010110"\n
"00011000"\n
"0"\n"000000000"\n"000000001"\n'

  0 0 0 1 1 0 0 0 
0 0 0 0 1 2 2 2 2 0  : left 左边1的个数
0 2 2 2 2 1 0 0 0 0  : right 右边0的个数

*/
