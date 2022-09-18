/*
 * @lc app=leetcode.cn id=66 lang=csharp
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.90%)
 * Likes:    1022
 * Dislikes: 0
 * Total Accepted:    494.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 71 25; 11 17 148 41.4;
    public int[] PlusOne(int[] digits) {
        int size = digits.Length;
        int carry = 1, i = size - 1;
        for(; i > -1; --i){
            int num = digits[i] + carry;
            if(num < 10){
                digits[i] = num;
                return digits;
            }else{
                digits[i] = num - 10;
                carry = 1;
            }
        }
        if(i == -1 && carry == 1){
            var ret = new int[size+1];
            ret[0] = 1;
            for(i = 0; i < size; ++i){
                ret[i+1] = digits[i];
            }
            return ret;
        }
        return digits;    // ? null
    }
}
// @lc code=end
/*
[1,2,4]\n
[4,3,2,1]\n
[0]\n
[9]
*/
