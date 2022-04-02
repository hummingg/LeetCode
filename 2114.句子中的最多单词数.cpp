/*
 * @lc app=leetcode.cn id=2114 lang=cpp
 *
 * [2114] 句子中的最多单词数
 */

// @lc code=start
class Solution {
public:
    // 56 24;
    int mostWordsFound(vector<string>& sentences) {
        int maxSpace = 0;
        for(auto str : sentences){
            int count = 0;
            for(auto ch : str){
                if(ch == ' '){
                    count++;
                }
            }
            if(count > maxSpace){
                maxSpace = count;
            }
        }
        return maxSpace + 1;
    }
};
// @lc code=end

