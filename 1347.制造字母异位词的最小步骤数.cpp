/*
 * @lc app=leetcode.cn id=1347 lang=cpp
 *
 * [1347] 制造字母异位词的最小步骤数
 */

// @lc code=start
class Solution {
public:
    // 79 91;
    int minSteps(string s, string t) {
        int sflag[26]{}, tflag[26]{};    // 初始化为0
        for(int i = 0; i < s.size(); i++){
            sflag[s[i]-'a']++;
            tflag[t[i]-'a']++;
        }
        
        int sum = 0;
        for(int i = 0; i < 26; i++){
            int diff = sflag[i] - tflag[i];
            if(diff > 0){
                sum += diff;
            }
        }
        return sum;
    }
};
// @lc code=end
/*
"bab"\n"aba"
"leetcode"\n"practice"
"anagram"\n"mangaar"
"xxyyzz"\n"xxyyzz"
"friend"\n"family"
*/
