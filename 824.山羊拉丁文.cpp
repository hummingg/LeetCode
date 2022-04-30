/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
public:
    // 100 62;
    string toGoatLatin(string sentence) {
        vector<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        string ret = "";
        int wordIndex = 1;
        for(int i = 0; i < sentence.size();++i){
            string word = "";
            string suffix = "ma" + string(wordIndex, 'a');
            if(find(v.begin(), v.end(), sentence[i]) == v.end()){
                suffix = sentence[i] + suffix;
                ++i;
            }
            while(i < sentence.size() && sentence[i] != ' '){
                word += sentence[i++];
            }
            ret += word + suffix;
            // if(i < sentence.size()){
                ret += ' ';
            // }
            ++wordIndex;
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end
/*
""a"\n"b"\n
"The quick brown fox jumped over the lazy dog""
*/
