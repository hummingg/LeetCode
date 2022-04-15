/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution {
public:
    // 100 49;
    int maxDepth(string s) {
        int maxDep = 0;
        int depth = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                depth++;
                if(depth > maxDep){
                    maxDep = depth;
                }
            }else if(s[i] == ')'){
                depth--;
            }
        }
        return maxDep;
    }
};
// @lc code=end

