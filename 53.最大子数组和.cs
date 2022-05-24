using System;
/*
 * @lc app=leetcode.cn id=53 lang=csharp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.91%)
 * Likes:    4878
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 子数组 是数组中的一个连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 * 
 */

// @lc code=start
public class Solution {
    // TLE
    public int MaxSubArray(int[] nums) {
        int ret = int.MinValue;
        for(int i = 0; i < nums.Length; ++i){
            int sum = 0;
            for(int j = i; j < nums.Length; ++j){
                sum += nums[j];
                ret = Math.Max(ret, sum);
            }
        }
        return ret;
    }
    // 错误思路
    public int MaxSubArray1(int[] nums) {
        int end = 0;
        int sum = nums[0];
        IList<int> il = new List<int>();
        int i = 1;
        for(; i < nums.Length; ++i){
            if(nums[i] <= 0 && nums[i-1] <= 0){
                sum += nums[i];
            }else if(nums[i] >= 0 && nums[i-1] >= 0){
                sum += nums[i];
            }else{
                // nums[end++] = sum;
                il.Add(sum);
                sum = nums[i];
            }
        }
        // nums[end++] = sum;
        il.Add(sum);
        // foreach(var num in il){
        //     Console.WriteLine(num);
        // }
        // Console.WriteLine(il);
        if(il.Count() == 1){
            if(il[0] < 0){
                return nums.Max(); // Math.Max(nums);
            }
            return il[0];
        }
        int ret;
        i = 1;
        if(il[0] >= 0){
            ret = il[0];
            i = 1;
        }else{
            ret = il[1];
            i = 2;
        }
        int preMax = ret;
        for(; i < il.Count()-1; i+=2){
            int nxtTwo = il[i] + il[i+1];   // 负 + 正
            if(nxtTwo >= 0){
                // if(preMax < il[i+1]){
                //     preMax = il[i+1];
                // }else{
                //     preMax += nxtTwo;
                // }
                preMax = Math.Max(preMax + nxtTwo, il[i+1]);
            }else{
                ret = Math.Max(ret, preMax);
                preMax = il[i+1];
            }
            // Console.WriteLine($"{ret}, {preMax}");
        }
        ret = Math.Max(ret, preMax);
        if(i == il.Count()-1){   // 负的

        }
        return ret;
    }
}
// @lc code=end
/*
[-2,1,-3,4,-1,2,1,-5,4]\n
[1]\n
[5,4,-1,7,8]\n
[9,-2,1,-1,9]
*/
