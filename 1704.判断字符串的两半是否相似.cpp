/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution {
    // 62 58 4 6.5;
public:
    bool halvesAreAlike(string s) {
        string yuanyin = "aeiouAEIOU";
        int count = 0;
        int size = s.size();
        for(int i = 0; i < size / 2; ++i){
            if(yuanyin.find_first_of(s[i]) != string::npos){
                ++count;
            }
        }
        for(int i = size/2; i < size; ++i){
            if(yuanyin.find_first_of(s[i]) != string::npos){
                --count;
            }
        }
        return count == 0;
    }
};
// @lc code=end

