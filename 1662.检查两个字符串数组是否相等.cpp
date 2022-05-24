/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
public:
    // 80 78;
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while(i1 < word1.size() // && j1 < word1[i1].size() 
            && i2 < word2.size()){  // && j2 < word2[i2].size()
            if(word1[i1][j1] != word2[i2][j2]){
                return false;
            }
            j1++;
            j2++;
            if(j1 == word1[i1].size()){
                i1++;
                j1 = 0;
            }
            if(j2 == word2[i2].size()){
                i2++;
                j2 = 0;
            }
        }
        return i1 == word1.size() && i2 == word2.size();
    }
};
// @lc code=end
/*
["ab", "c"]\n["a", "bc"]\n
["a", "cb"]\n["ab", "c"]\n
["abc", "d", "defg"]\n["abcddefg"]\n
["abc","d","defg"]\n["abcddef"]
*/