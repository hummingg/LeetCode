using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=49 lang=csharp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.30%)
 * Likes:    1161
 * Dislikes: 0
 * Total Accepted:    335.5K
 * Total Submissions: 498.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 88 19; 68 42 176 65.8;
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        // var dic = new Dictionary<int[], string>();  // int[]无法Key
        // dic.Add(new int[26], "a");
        // dic.Add(new int[26], "b");
        var dic = new Dictionary<string, List<string>>();
        foreach(var str in strs){
            var cnt = new int[26];
            foreach(var c in str){
                ++cnt[c-'a'];
            }
            string strCnt = string.Join(',', cnt);
            if(dic.ContainsKey(strCnt)){
                dic[strCnt].Add(str);
            }else{
                dic.Add(strCnt, new List<string>(){str});
            }
        }
        var ret = new List<IList<string>>();
        foreach(var kvp in dic){
            // Console.WriteLine($"{kvp.Key}: {string.Join(',', kvp.Value)}");
            ret.Add(kvp.Value);
        }
        return ret;
    }
}
// @lc code=end
/*
["eat", "tea", "tan", "ate", "nat", "bat"]\n
[""]\n
["a"]
*/
