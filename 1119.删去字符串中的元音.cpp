/*
 * @lc app=leetcode.cn id=1119 lang=cpp
 *
 * [1119] 删去字符串中的元音
 *
 * https://leetcode-cn.com/problems/remove-vowels-from-a-string/description/
 *
 * algorithms
 * Easy (86.73%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 10.6K
 * Testcase Example:  '"leetcodeisacommunityforcoders"'
 *
 * 给你一个字符串 s ，请你删去其中的所有元音字母 'a'，'e'，'i'，'o'，'u'，并返回这个新字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "leetcodeisacommunityforcoders"
 * 输出："ltcdscmmntyfrcdrs"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aeiou"
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 1000
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 100 68; 100 80;
    string removeVowels(string s) {
        string pattern = "aeiou", ret = "";
        for(char c : s){
            if(pattern.find_first_of(c) == string::npos){
                ret += c;
            }
        }
        return ret;
    }
};
// @lc code=end

