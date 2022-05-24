/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    // 100 61; 100 43;
    string mergeAlternately(string word1, string word2) {
        string ret = "";
        int minSize = min(word1.size(), word2.size());
        for(int i = 0; i < minSize; ++i){
            ret += string(1, word1[i]) + string(1, word2[i]);
        }
        if(word1.size() > minSize){
            ret += word1.substr(minSize);
        }
        if(word2.size() > minSize){
            ret += word2.substr(minSize);
        }
        return ret;
    }
};
// @lc code=end

