/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // 长度不一样则false
        if(s.size() == 1 || goal.size() == 1 || s.size() != goal.size()){
            return false;
        }

        // 相同且有重复字母则true
        if(s == goal){
            bool letter_flags[26] = { false };  // 是否已出现过
            for(int i = 0; i < s.size(); i++){
                int chIndex = s[i] - 'a';
                if(letter_flags[chIndex]){
                    return true;
                }else{
                    letter_flags[chIndex] = true;
                }
            }
            return false;
        }

        // 不相同则逐个比较，找不同的字母，计算不同的次数
        bool used = false;  // 是否已使用交换机会
        char diff_ch1 = ' ', diff_ch2 = ' ';
        for(int i = 0; i < s.size(); i++){
            if(s[i] != goal[i]){
                if(diff_ch1 == diff_ch2){   // 首次不同
                    diff_ch1 = s[i];
                    diff_ch2 = goal[i];
                }else{  // 第二次不同
                    if(diff_ch1 == goal[i] && diff_ch2 == s[i] && !used){
                        used = true;
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return used;
    }
};

// int main(){
//     Solution s;
//     // "aaaaaaabc"\n"aaaaaaacb""
//     string str1 = "aaaaaaabc";
//     string str2 = "aaaaaaacb";
//     cout << s.buddyStrings(str1, str2) << endl;
//     return 0;
// }
// @lc code=end

