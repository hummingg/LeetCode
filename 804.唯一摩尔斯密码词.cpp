/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution {
public:
    // 100 55;
    int uniqueMorseRepresentations(vector<string>& words) {
        string mosi[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        int size = words.size();
        for(int i = 0; i < size; ++i){
            string str = "";
            string word = words[i];
            for(int j = 0; j < word.size(); ++j){
                str += mosi[word[j]-'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};
// @lc code=end

