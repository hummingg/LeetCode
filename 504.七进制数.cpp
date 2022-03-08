/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        // if(num == 0){
        //     return "0";
        // }

        int n = abs(num);
        string s = "";

        // while(n>0){
        //     s = to_string(n%7) + s;
        //     n = n/7;
        // }

        do{
            s = to_string(n%7) + s;
            n = n/7;
        }while(n>0);

        if(num < 0){
            s = "-" + s;
        }
        return s;
    }
};
// @lc code=end

