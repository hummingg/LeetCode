/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.24%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    408.2K
 * Total Submissions: 625.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
    // 11 46;
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        // string u = "我";
        // cout << typeid(u).name() << endl;
        // cout << typeid(s).name() << endl;
        // cout << u << endl;
        map<char32_t, int> m;
        // char32_t c = U'我';
        // cout << c << endl;
        for(int i = 0; i < s.size(); ++i){
            ++m[s[i]];
        }
        for(int i = 0; i < t.size(); ++i){
            --m[t[i]];
            if(m[t[i]] < 0){
                return false;
            }
        }
        for(auto &[_, v] : m){
            if(v != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
/*
""rat"\n"car"\n
"我爱学习"\n"学习爱我""
*/
