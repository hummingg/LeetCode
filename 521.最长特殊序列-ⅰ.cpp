/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 52;
    int findLUSlength(string a, string b) {
        int sizea = a.size();
        int sizeb = b.size();
        if(sizea != sizeb){
            if(sizea > sizeb){
                return sizea;
            }
            return sizeb;
        }
        if(a != b){
            return sizea;
        }

        return -1;
    }
};
// @lc code=end

