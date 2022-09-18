/*
 * @lc app=leetcode.cn id=503 lang=csharp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (65.35%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    144.1K
 * Total Submissions: 220.3K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 * 下一个更大元素 。
 * 
 * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
 * 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 85 32; 83 47 148 55;
    // 单调递减栈
    public int[] NextGreaterElements(int[] nums) {
        var ret = new int[nums.Length];
        var stk = new Stack<int>();
        stk.Push(0);
        ret[0] = -1;
        for(int i = 1; i < nums.Length; ++i){
            ret[i] = -1;
            while(stk.Count > 0 && nums[i] > nums[stk.Peek()]){
                ret[stk.Pop()] = nums[i];
            }
            stk.Push(i);
        }
        for(int i = 0; i < nums.Length; ++i){
            while(stk.Count > 0 && i < stk.Peek() && nums[i] > nums[stk.Peek()]){
                ret[stk.Pop()] = nums[i];
            }
        }
        return ret;
    }
}
// @lc code=end
/*
[1,2,1]\n
[1,2,3,4,3]
*/
