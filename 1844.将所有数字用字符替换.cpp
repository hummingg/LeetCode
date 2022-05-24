/*
 * @lc app=leetcode.cn id=1844 lang=cpp
 *
 * [1844] 将所有数字用字符替换
 */

// @lc code=start
class Solution {
    // 100 80;
public:
    string replaceDigits(string s) {
        int size = s.size();
        for(int i = 0; i < size-1; i+=2){
            s[i+1] = s[i] + (s[i+1]-'0');
        }
        return s;
    }
};
// @lc code=end

