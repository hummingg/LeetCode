/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
public:
    // 32 6,9;
    bool checkIfPangram(string sentence) {
        set<char> sc;
        for(char c = 'a'; c <= 'z'; c++){
            sc.insert(c);
        }
        int i = 0;
        while(i < sentence.size() && !sc.empty()){
            sc.erase(sentence[i++]);
        }
        return sc.empty();
    }
};
// @lc code=end

