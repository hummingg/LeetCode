/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
public:
    // 100 70;
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int count = 0;
        int row = 1;
        for(int i = 0; i < s.size(); ++i){
            if(count + widths[s[i]-'a'] <= 100){
                count += widths[s[i]-'a'];
            }else{
                ++row;
                count = 0;
                --i;
            }
        }
        return {row, count};
    }
};
// @lc code=end
/*
[10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]\n"abcdefghijklmnopqrstuvwxyz"
[4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]\n"bbbcccdddaaa"
*/
