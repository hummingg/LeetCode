/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <map>
#include <cmath>
using namespace std;


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mCharIndex;
        int begin = 0, maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            auto it = mCharIndex.find(s[i]);
            if(it == mCharIndex.end()){
                mCharIndex.insert(make_pair(s[i], i));
            }else{
                maxLen = max(maxLen, i - begin);
                int repeat = mCharIndex[s[i]];

                for(int j = begin; j < repeat; j++ ){
                    mCharIndex.erase(s[j]);
                }
                mCharIndex[s[i]] = i;
                begin = repeat + 1;
            }
        }
        maxLen = max(maxLen, (int)(s.size()) - begin);  // size_t不是int

        return maxLen;
    }
};
// @lc code=end

