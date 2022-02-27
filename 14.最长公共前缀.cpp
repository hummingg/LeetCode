/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0){
            return "";
        }else if(size == 1){
            return strs[0];
        }

        string prefix = "";
        for(int i = 0; ; i++){
            char ch;
            for(int j = 0; j < size; j++){  // 比较str[j][i]
                if(j == 0){
                    if(i >= strs[j].size()){
                        return prefix;
                    }
                    ch = strs[j][i];
                    continue;
                }
                if(i >= strs[j].size() || ch != strs[j][i]){
                    return prefix;
                }
            }
            prefix += ch;
        }

        return prefix;
    }
};
// @lc code=end

