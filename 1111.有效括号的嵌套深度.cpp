/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

// @lc code=start
class Solution {
public:
    // 100 48;
    // 把最深的平均拆开为a>=b，其他>a的也要拆为a+c
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> v(seq.size());
        int maxDepth = 0;
        int depth = 0;
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                depth++;
                maxDepth = max(maxDepth, depth);
            }else{
                depth--;
            }
        }
        int allowedDepth = (maxDepth+1) /2;
        depth = 0;
        stack<int> stk; // 左括号索引
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                depth++;
                stk.push(i);
            }else{
                if(depth > allowedDepth){   // 所在深度太深了，挖出来
                    v[i] = 1;
                    v[stk.top()] = 1;
                }
                depth--;
                stk.pop();
            }
        }
        return v;
    }
};
// @lc code=end

