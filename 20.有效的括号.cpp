/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    // 100 88;
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m;
        m.insert({')', '('});   // m[')'] = '(';
        m.insert({'}', '{'});
        m.insert({']', '['});
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }else{
                if(!stk.empty() && stk.top() == m[s[i]]){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
/*
""]""
*/
