/*
 * @lc app=leetcode.cn id=709 lang=csharp
 *
 * [709] 转换成小写字母
 *
 * https://leetcode.cn/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (77.31%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    106.8K
 * Total Submissions: 138.1K
 * Testcase Example:  '"Hello"'
 *
 * 给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Hello"
 * 输出："hello"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "here"
 * 输出："here"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "LOVELY"
 * 输出："lovely"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由 ASCII 字符集中的可打印字符组成
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 66 62;
    public string ToLowerCase(string s) {
        string ret = "";
        for(int i = 0; i < s.Length; ++i){
            // 65 90 97 122
            if(s[i] >= 65 && s[i] <= 90){
                // s[i] = s[i] + 32;   // read only
                ret += ((char)(s[i] + 32)).ToString();
            }else{
                ret += s[i].ToString();
            }
        }
        return ret;
    }
}
// @lc code=end

