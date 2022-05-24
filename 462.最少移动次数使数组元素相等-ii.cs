using System;
/*
 * @lc app=leetcode.cn id=462 lang=csharp
 *
 * [462] 最少移动次数使数组元素相等 II
 *
 * https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (61.42%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissions: 29.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。
 * 
 * 在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：2
 * 解释：
 * 只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,10,2,9]
 * 输出：16
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 100 88;
    public int MinMoves2(int[] nums) {
        Array.Sort(nums);
        int median = (nums[(nums.Length-1)/2] + nums[nums.Length/2]) / 2;
        // Console.WriteLine(median);
        int ret = nums.Aggregate((result, next) => result + Math.Abs(next-median)) - nums[0]+ Math.Abs(nums[0]-median); // + Math.Abs(nums[0]-median); // reduce
        // Console.WriteLine(ret);
        return ret;
    }

    // WA 平均数
    public int MinMoves29(int[] nums) {
        long sum = 0;
        int size = nums.Length;
        for(int i = 0; i < size; ++i){
            sum += nums[i];
        }
        double avg = 1.0 * sum / size;
        int avgi = Math.Floor(avg) == (int)avg ? (int)avg : ((int)avg+1);
        Console.WriteLine(avgi);
        int ret = 0;
        foreach(int num in nums){
            ret += Math.Abs(num - avgi);
        }
        return ret;
    }
}
// @lc code=end
/*
[1]\n
[1,2,3]\n
[1,10,2,9]\n
[1,0,0,8,6]
3: 2 3 3 5 3
2: 1 2 2 6 4
1: 0 1 1 7 5
*/
