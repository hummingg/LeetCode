/*
 * @lc app=leetcode.cn id=2108 lang=cpp
 *
 * [2108] 找出数组中的第一个回文字符串
 */

// @lc code=start
class Solution {
    // 97 21;
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            if(isPali(words[i])){
                return words[i];
            }
        }
        return "";
    }

    // 空字符串也算回文
    bool isPali(string str){
        int low = 0, high = str.size()-1;
        while(low < high && str[low] == str[high]){
            ++low;
            --high;
        }
        return low >= high;
    }
};
// @lc code=end

