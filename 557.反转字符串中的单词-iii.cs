using System.Text;
/*
 * @lc app=leetcode.cn id=557 lang=csharp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.17%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    240.6K
 * Total Submissions: 324.3K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： s = "God Ding"
 * 输出："doG gniD"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 52.02%(84ms) 46.37%(47.7MB) 29
    public string ReverseWords(string s) {
        var ret = new StringBuilder();
        var sb = new StringBuilder();
        foreach(var c in s){
            if(c == ' '){
                ret.Append(sb.ToString());
                sb = new StringBuilder();
                ret.Append(' ');
            }else{
                sb.Insert(0, c);
            }
        }
        ret.Append(sb.ToString());
        return ret.ToString();
    }
}
// @lc code=end

