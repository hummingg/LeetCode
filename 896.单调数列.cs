/*
 * @lc app=leetcode.cn id=896 lang=csharp
 *
 * [896] 单调数列
 *
 * https://leetcode.cn/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (57.91%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    69.1K
 * Total Submissions: 119.4K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是 单调 的。
 * 
 * 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> =
 * nums[j]，那么数组 nums 是单调递减的。
 * 
 * 当给定的数组 nums 是单调数组时返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [6,5,4,4]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,3,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 83 82;
    public bool IsMonotonic(int[] nums) {
        if(nums.Length < 3){
            return true;
        }
        int isIncre = 0;
        for(int i = 1; i < nums.Length; ++i){
            int diff = nums[i-1] - nums[i];
            if(diff == 0){
                continue;
            }
            if(isIncre != 0){
                if(diff > 0 && isIncre != 1 || diff < 0 && isIncre != -1){
                    return false;
                }
            }else{
                if(diff > 0){
                    isIncre = 1;
                }else{
                    isIncre = -1;
                }
            }
        }
        return true;
    }
}
// @lc code=end

