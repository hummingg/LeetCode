/*
 * @lc app=leetcode.cn id=989 lang=csharp
 *
 * [989] 数组形式的整数加法
 *
 * https://leetcode.cn/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (46.95%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    61.3K
 * Total Submissions: 130.5K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
 * 
 * 
 * 例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
 * 
 * 
 * 给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num = [1,2,0,0], k = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num = [2,7,4], k = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num = [2,1,5], k = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 10^4
 * 0 <= num[i] <= 9
 * num 不包含任何前导零，除了零本身
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 32 55; 21 77 184 55.6;
    public IList<int> AddToArrayForm(int[] num, int k) {
        int carry = 0;
        IList<int> ret = new List<int>();
        for(int i = num.Length - 1; i >= 0; --i){
            int partSum = num[i] + k % 10 + carry;
            carry = partSum / 10;
            ret.Insert(0, partSum % 10);
            k /= 10;
        }
        k += carry;
        while(k > 0){
            ret.Insert(0, k % 10);
            k /= 10;
        }
        return ret;
    }
}
// @lc code=end
/*
[1,2,0,0]\n34\n
[2,7,4]\n181\n
[2,1,5]\n806\n
[0]\n23
*/
