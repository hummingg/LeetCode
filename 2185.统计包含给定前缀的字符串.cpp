/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution {
    // 45 48;
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, len = pref.size();
        for(int i = 0; i < words.size(); ++i){
            // if(startWith(words[i], pref)){   // 45 16;
            if(words[i].substr(0, len) == pref){
                ++count;
            }
        }
        return count;
    }

    bool startWith(string str, string pref){
        if(pref.size() == 0){
            return true;
        }
        for(int i = 0; i < pref.size(); ++i){
            if(i >= str.size() || str[i] != pref[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
/*
["leetcode","win","loops","success"]\n"code"
*/
