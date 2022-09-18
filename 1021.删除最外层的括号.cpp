/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
    // 100 49;
public:
    string removeOuterParentheses(string s) {
        string ret;
        int left = 0;
        int size = s.size();
        for(int i = 0; i < size; ++i){
            if(s[i] == '('){
                ++left;
                if(left > 1){
                    ret += '(';
                }
            }else{
                --left;
                if(left > 0){
                    ret += ')';
                }
            }
        }
        return ret;
    }
};
// @lc code=end

