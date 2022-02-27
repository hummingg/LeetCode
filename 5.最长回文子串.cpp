/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string result = "";
        int size = s.size();
        int midIndex = size / 2;
        for(int i = 0; i < size; i++){
            // midIndex+0.5*i 为中心
                
            // midIndex-0.5*i 为中心
        }
    }
};
// @lc code=end

