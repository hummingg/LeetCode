using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=496 lang=csharp
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode-cn.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (71.06%)
 * Likes:    700
 * Dislikes: 0
 * Total Accepted:    177.5K
 * Total Submissions: 249.8K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 * 
 * 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
 * 
 * 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定
 * nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
 * 
 * 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出：[-1,3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
 * - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出：[3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
 * - 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * nums1和nums2中所有整数 互不相同
 * nums1 中的所有整数同样出现在 nums2 中
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
 * 
 */

// int[] nums1 = {4,1,2}, nums2 = {1,3,4,2};
int[] nums1 = {2,4}, nums2 = {1,2,3,4};
// string[] strs = {"zyx","wvu","tsr"};
Console.WriteLine(new Solution().NextGreaterElement(nums1, nums2));

// @lc code=start
public class Solution {
    // 14 21; 70 23; 86 40; 96 14; 53 23;
    public int[] NextGreaterElement(int[] nums1, int[] nums2) {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        var ret = new int[len1];
        var dict = new Dictionary<int,int>();

        for(int i = 0; i < len2; ++i){
            dict[nums2[i]] = i;
            // dict.Add(nums2[i], i);
        }
        // foreach(KeyValuePair<int,int> kvp in dict){
        //     Console.WriteLine("Key = {0}, Value = {1}",kvp.Key, kvp.Value);
        // }
        for(int i = 0; i < len1; ++i){
            int j = dict[nums1[i]] + 1;
            while(j < len2 && nums2[j] <= nums1[i]){
                ++j;
            }
            ret[i] = j == len2 ? -1 : nums2[j];
            // Console.Write(ret[i] + " ");
        }
        return ret;
    }
}
// @lc code=end
/*
[4,1,2]\n[1,3,4,2]\n
[2,4]\n[1,2,3,4]
*/
