using System.Text;
/*
 * @lc app=leetcode.cn id=459 lang=csharp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (50.84%)
 * Likes:    699
 * Dislikes: 0
 * Total Accepted:    117.1K
 * Total Submissions: 230.3K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "aba"
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 66 34; 88 31 68 52.3;
    public bool RepeatedSubstringPattern(string s) {
        int size = s.Length;
        for(int i = size / 2; i > 0; --i){
            if(size % i == 0){
                string pattern = s.Substring(0, i);
                // var sb = new StringBuilder();
                // for(int j = 0; j < size / i; ++j){
                //     sb.Append(pattern);
                // }
                // if(s == sb.ToString()){
                //     return true;
                // }
                int j = i;
                while(j < size && s.Substring(j, i) == pattern){
                    j += i;
                }
                if(j == size){
                    return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end
/*
'"abab"\n
"aba"\n
"abcabcabcabc"'
*/
