/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(s == "" || numRows == 1){
            return s;
        }
        int size = s.size();
        int n = numRows * 2 -2; // 周期

        string result = "";
        for(int i = 0; i < numRows; i++){
            int interval = (numRows - 1 - i) * 2;            
            for(int index = i; index < size; index += n){
                result += s[index];
                if(interval != 0 && interval != n && index+interval < size){
                    result += s[index+interval];
                }
            }
        }

        return result;
    }
    // n = numRows = 4
    // numRows * 2 - 2 = 6
    // i=0: +6      n-(i+1) + (n-1-i) = 6, 6-6=0
    // i=1: +4, +2  n-(i+1) + (n-1-i) = 4, 6-4=2
    // i=2: +2, +4  n-(i+1) + (n-1-i) = 2, 6-2=4
    // i=3: +6      n-(i+1) + (n-1-i) = 0, 6-0=6
    /*
    numRows = 4
    0    P0      I6       N12
    1    A1   L5 S7   I11 G13
    2    Y2 A4   H8 R10    14
    3    P3      I9        15
    numRows = 3
    0   4   8
    1 3 5 7
    2   6 
    */
};
// @lc code=end

