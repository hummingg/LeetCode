using System.Linq;
using System.Text;
using System.Collections.Generic;
using System;
/*
 * @lc app=leetcode.cn id=522 lang=csharp
 *
 * [522] 最长特殊序列 II
 *
 * https://leetcode.cn/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 26.3K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * 给定字符串列表 strs ，返回其中 最长的特殊序列 。如果最长特殊序列不存在，返回 -1 。
 * 
 * 特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。
 * 
 * s 的 子序列可以通过删去字符串 s 中的某些字符实现。
 * 
 * 
 * 例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc"
 * 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: strs = ["aba","cdc","eae"]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = ["aaa","aaa","aa"]
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= strs.length <= 50
 * 1 <= strs[i].length <= 10
 * strs[i] 只包含小写英文字母
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 9 9 156 69.1;
    public int FindLUSlength(string[] strs) {
        var count = new Dictionary<string,int>();
        var subs = new Dictionary<string, List<string>>();
        int size = strs.Length;
        for(int i = 0; i < size; ++i){
            var set = new HashSet<string>();
            for(int j = 0; j < (1 << strs[i].Length); ++j){
                var sb = new StringBuilder();
                for(int k = 0; k < strs[i].Length; ++k){
                    if((j & (1 << k)) > 0){
                        sb.Append(strs[i][k]);
                    }
                }
                set.Add(sb.ToString());
            }
            if(!subs.ContainsKey(strs[i])){
                subs.Add(strs[i], new List<string>(set));
            }else{
                subs[strs[i]].AddRange(set);
            }
        }
        foreach(var kvp in subs){
            foreach(var sub in kvp.Value){
                if(!count.ContainsKey(sub)){
                    count.Add(sub, 1);
                }else{
                    count[sub]++;
                }
            }
        }
        int ret = -1;
        foreach(var kvp in count){
            // Console.WriteLine($"{kvp.Key}: {kvp.Value}");
            if(kvp.Value == 1){
                ret = Math.Max(ret, kvp.Key.Length);
            }
        }
        return ret == 0 ? -1 : ret;
    }

    // 26进制，错误思路
    public int FindLUSlength9(string[] strs) {
        Array.Sort(strs, (str1, str2) => str2.Length - str1.Length);
        // return 0;
        int size = strs.Length;
        
        var mask = new int[size,10];
        for(int i = 0; i < size; ++i){
            // Console.WriteLine($"{strs[i]}");
            for(int j = 0; j < strs[i].Length; ++j){
                mask[i,j] = (int)strs[i][j];
            }
        }
        for(int i = 0; i < size; ++i){
            bool common = false;
            for(int j = 0; j < 10; ++j){
                // Console.WriteLine($"{mask[i,j]} ");
                if(strs[j].Length < strs[i].Length){
                    break;
                }
                if(j == i){
                    continue;
                }
                for(int k = 0; k < 10; ++k){
                    
                }
            }
            // Console.WriteLine();
            if(!common){
                return strs[i].Length;
            }
        }
        return -1;
    }
}
// @lc code=end
/*
["aba","cdc","eae"]\n
["aaa","aaa","aa"]
*/
