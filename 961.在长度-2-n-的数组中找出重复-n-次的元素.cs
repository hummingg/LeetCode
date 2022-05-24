using System;
/*
 * @lc app=leetcode.cn id=961 lang=csharp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 *
 * https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (67.66%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 60.9K
 * Testcase Example:  '[1,2,3,3]'
 *
 * 给你一个整数数组 nums ，该数组具有以下属性：
 * 
 * 
 * 
 * 
 * nums.length == 2 * n.
 * nums 包含 n + 1 个 不同的 元素
 * nums 中恰有一个元素重复 n 次
 * 
 * 
 * 找出并返回重复了 n 次的那个元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,3]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,1,2,5,3,2]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,1,5,2,5,3,5,4]
 * 输出：5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 5000
 * nums.length == 2 * n
 * 0 <= nums[i] <= 10^4
 * nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 76 100;
    public int RepeatedNTimes(int[] nums) {
        if(nums[0] == nums[3] || nums[1] == nums[3]){
            return nums[3];
        }
        if(nums[0] == nums[2]){
            return nums[0];
        }
        
        for(int i = 1; i < nums.Length; ++i){
            if(nums[i-1] == nums[i]){
                return nums[i];
            }
        }
        return -1;
    }
    // 100 62;
    public int RepeatedNTimes2(int[] nums) {
        var hashSet = new HashSet<int>();
        for(int i = 0; i < nums.Length; ++i){
            // if(hashSet.Contains(nums[i])){  // n + 1 个 不同元素
            //     return nums[i];
            // }else{
            //     hashSet.Add(nums[i]);
            // }
            if(!hashSet.Add(nums[i])){
                return nums[i];
            }
        }
        return -1;
    }
    // 86 100;
    public int RepeatedNTimes1(int[] nums) {
        Array.Sort(nums);
        int n2 = nums.Length;
        // n/2-1 前半最后一个
        int n = n2/2;
        if(nums[n-1] == nums[n-2]){
            return nums[n-1];
        }
        return nums[n];
    }
}
// @lc code=end
/*
[1,2,3,3]\n
[2,1,2,5,3,2]\n
[5,1,5,2,5,3,5,4]
*/
