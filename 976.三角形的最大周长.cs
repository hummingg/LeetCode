/*
 * @lc app=leetcode.cn id=976 lang=csharp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode-cn.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (58.86%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    65.5K
 * Total Submissions: 111.3K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回
 * 0。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,1,2]
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
public class Solution {
    public int LargestPerimeter(int[] nums) {
        Array.Sort(nums);
        for (int i = nums.Length - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
}
// @lc code=end

