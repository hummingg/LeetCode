/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (68.51%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    124K
 * Total Submissions: 181K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "", t = "y"
 * 输出："y"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 优化时间 n * n
    // 61 11; 61 6; 100 13;
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        // for(int i = 0; i < s.size(); ++i){
        for(auto c : s){
            ++m[c];
        }
        // for(int i = 0; i < t.size(); ++i){
        for(auto c : t){
            --m[c];
            if(m[c] == -1){
                return c;
            }
        }
        return m.begin()->first;    // 不会执行到
    }

    // nlogn * n
    // 61 57;
    char findTheDifference1(string s, string t) {
        // string str = "cba";
        // sort(str.begin(), str.end());
        // cout << str << endl;
        sort(s.begin(), s.end());
        // cout << s << endl;
        sort(t.begin(), t.end());
        // cout << t << endl;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return t.back();
    }
};
// @lc code=end
/*
"""\n"y""
*/
