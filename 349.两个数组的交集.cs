/*
 * @lc app=leetcode.cn id=349 lang=csharp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.17%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    301.9K
 * Total Submissions: 407K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 92 5 124 42.7;
    public int[] Intersection(int[] nums1, int[] nums2) {
        var set1 = new HashSet<int>();
        var set2 = new HashSet<int>();
        foreach(var num in nums1){
            set1.Add(num);
        }
        foreach(var num in nums2){
            set2.Add(num);
        }
        var ret = new List<int>();
        foreach(var num in set1){
            if(set2.Contains(num)){
                ret.Add(num);
            }
        }
        return ret.ToArray();
    }
}
// @lc code=end

