/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution {
public:
// 100 19;
    string interpret(string command) {
        string ret = "";
        for(int i = 0; i < command.size();){
            if(command[i] == 'G'){
                ret += "G";
                i++;
            }else if(command[i] == '('){
                if(command[i+1] == ')'){    // ()
                    ret += "o";
                    i += 2;
                }else{  // (al)
                    ret += "al";
                    i += 4;
                }
            }else{
                return ret;
            }
        }
        return ret;
    }
};
// @lc code=end

