/*
 * @lc app=leetcode.cn id=1869 lang=cpp
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start
class Solution {
    // 100 81 0 5.9;
public:
    bool checkZeroOnes(string s) {
        int len1 = 0, len0 = 0, maxLen1 = 0, maxLen0 = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1'){
                ++len1;
                if(len1 > 1){
                    continue;
                }
                maxLen0 = max(maxLen0, len0);
                len0 = 0;
            }else{
                ++len0;
                if(len0 > 1){
                    continue;
                }
                maxLen1 = max(maxLen1, len1);
                len1 = 0;
            }
        }
        maxLen0 = max(maxLen0, len0);
        maxLen1 = max(maxLen1, len1);
        return maxLen1 > maxLen0;
    }
};
// @lc code=end

