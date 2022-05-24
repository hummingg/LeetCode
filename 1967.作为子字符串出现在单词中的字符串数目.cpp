/*
 * @lc app=leetcode.cn id=1967 lang=cpp
 *
 * [1967] 作为子字符串出现在单词中的字符串数目
 */

// @lc code=start
class Solution {
    // 93 36;
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(int i = 0; i < patterns.size(); ++i){
            string pattern = patterns[i];
            if(word.find(pattern) != string::npos ){   //  find_first_of
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end
/*
["a","abc","bc","d"]\n"abc"
["a","b","c"]\n"aaaaabbbbb"
["a","a","a"]\n"ab"
["cjevwg"]\n"jevwg"
*/