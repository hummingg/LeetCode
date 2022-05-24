/*
 * @lc app=leetcode.cn id=2185 lang=csharp
 *
 * [2185] 统计包含给定前缀的字符串
 *
 * https://leetcode.cn/problems/counting-words-with-a-given-prefix/description/
 *
 * algorithms
 * Easy (79.52%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 13.5K
 * Testcase Example:  '["pay","attention","practice","attend"]\n"at"'
 *
 * 给你一个字符串数组 words 和一个字符串 pref 。
 * 
 * 返回 words 中以 pref 作为 前缀 的字符串的数目。
 * 
 * 字符串 s 的 前缀 就是  s 的任一前导连续字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["pay","attention","practice","attend"], pref = "at"
 * 输出：2
 * 解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["leetcode","win","loops","success"], pref = "code"
 * 输出：0
 * 解释：不存在以 "code" 作为前缀的字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length, pref.length <= 100
 * words[i] 和 pref 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 78 68;
    public int PrefixCount(string[] words, string pref) {
        int count = 0, len = pref.Length;
        for(int i = 0; i < words.Length; ++i){
            if(words[i].Length >= len && words[i].Substring(0, len) == pref){
                ++count;
            }
        }
        return count;
    }
}
// @lc code=end

