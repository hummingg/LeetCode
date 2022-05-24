/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
    // 100 25;
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); ++i){
            // 65 90 97 122
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};
// @lc code=end
/*
"al&phaBET"
*/
