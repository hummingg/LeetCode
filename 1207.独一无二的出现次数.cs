using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=1207 lang=csharp
 *
 * [1207] 独一无二的出现次数
 *
 * https://leetcode.cn/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (72.94%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    65.2K
 * Total Submissions: 89.4K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
 * 
 * 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,2,1,1,3]
 * 输出：true
 * 解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,2]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 64: 86.36%(88ms) 90.91%(39.1MB);
    public bool UniqueOccurrences(int[] arr) {
        var dic = new Dictionary<int,int>();
        foreach(var num in arr){
            if(dic.ContainsKey(num)){
                dic[num]++;
            }else{
                dic.Add(num, 1);
            }
        }
        var hashSet = new HashSet<int>();
        foreach(var kvp1 in dic){
            // foreach(var kvp2 in dic){
            //     if(kvp1.Key != kvp2.Key && kvp1.Value == kvp2.Value){
            //         return false;
            //     }
            // }
            if(!hashSet.Add(kvp1.Value)){
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

