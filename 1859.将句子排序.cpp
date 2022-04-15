/*
 * @lc app=leetcode.cn id=1859 lang=cpp
 *
 * [1859] 将句子排序
 */

// @lc code=start
class Solution {
public:
    // 100 90;
    string sortSentence(string s) {
        // vector<string> vs(10, "");
        string vs[10] = {""};
        string str = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                vs[s[i] - '0'] = str;
                str = "";
                ++i;
            }else{
                str += s[i];
            }
        }
        for(int j = 1; j < 10 && vs[j] != ""; ++j){
            str += vs[j] + " ";
        }
        str.pop_back();
        return str;
    }
};
// @lc code=end
/*
""is2 sentence4 This1 a3"\n"Myself2 Me1 I4 and3""
*/
