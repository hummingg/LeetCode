/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 *
 * https://leetcode-cn.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (55.37%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 36.3K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * 某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
 * 
 * 给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回
 * false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"
 * 输出：true
 * 解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["word","world","row"]\n"worldabcefghijkmnpqstuvxyz"
 * 输出：false
 * 解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["apple","app"]\n"abcdefghijklmnopqrstuvwxyz"
 * 输出：false
 * 解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中
 * '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * order.length == 26
 * 在 words[i] 和 order 中的所有字符都是英文小写字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 86 27; 100 42;
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for(int i = 0; i < order.size(); ++i){
            m[order[i]] = i;
        }
        // cout<<m[0x00]<<endl;    // 默认 0
        for(int i = 0; i < words.size()-1; ++i){
            string first = words[i];
            string second = words[i+1];
            int j = 0;
            int size = min(first.size(), second.size());
            // for(; j < first.size(); ++j){   // 怎么通过的？
            for(; j < size; ++j){
                // if(j >= size){
                //     cout << "越界了" << endl;
                //     cout << second[j] << endl;  // \x00 == 0x00，\x是转义字符
                //     cout << to_string(m[second[j]]) << endl;    // 默认 0，原来如此
                // }
                if(m[first[j]] < m[second[j]]){
                    cout << "<<<" << endl;
                    break;
                }else if(m[first[j]] > m[second[j]]){
                    // cout << ">>>" << endl;
                    return false;
                }
            }
            // if(j == first.size() && first.size() > second.size()){   // 怎么通过的？
            if(j == size && first.size() > second.size()){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
/*
["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"\n
["word","world","row"]\n"worldabcefghijkmnpqstuvxyz"\n
["apple","app"]\n"abcdefghijklmnopqrstuvwxyz"\n
["app","apple"]\n"abcdefghijklmnopqrstuvwxyz"\n
["aa","a"]\n"abqwertyuioplkjhgfdszxcvnm"\n
["hello","hello"]\n"abcdefghijklmnopqrstuvwxyz"
*/
