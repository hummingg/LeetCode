using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=532 lang=csharp
 *
 * [532] 数组中的 k-diff 数对
 *
 * https://leetcode.cn/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 76.3K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要在数组里找到 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
 * 
 * 这里将 k-diff 数对定义为一个整数对 (nums[i], nums[j])，并满足下述全部条件：
 * 
 * 
 * 0 <= i < j < nums.length
 * |nums[i] - nums[j]| == k
 * 
 * 
 * 注意，|val| 表示 val 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3, 1, 4, 1, 5], k = 2
 * 输出：2
 * 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
 * 尽管数组中有两个1，但我们只应返回不同的数对的数量。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1, 2, 3, 4, 5], k = 1
 * 输出：4
 * 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1, 3, 1, 5, 4], k = 0
 * 输出：1
 * 解释：数组中只有一个 0-diff 数对，(1, 1)。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 29 76;
    public int FindPairs(int[] nums, int k) {
        var dic = new SortedDictionary<int,int>();
        foreach(var num in nums){
            if(dic.ContainsKey(num)){
                dic[num]++;
            }else{
                dic.Add(num, 1);
            }
        }
        int ret = 0;
        foreach(var kvp in dic){
            if(k == 0 && kvp.Value > 1 || k > 0 && dic.ContainsKey(kvp.Key + k)){
                ++ret;
            }
        }
        return ret;
    }
}
// @lc code=end
/*
[3, 1, 4, 1, 5]\n2\n
[1, 2, 3, 4, 5]\n1\n
[1, 3, 1, 5, 4]\n0
*/
