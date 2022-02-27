/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pointer_1 = 0, pointer_2 = 0, count_1 = 0, count_2 = 0;
        char ch;
        while(pointer_1 < name.size() && pointer_2 < typed.size()){
            ch = name[pointer_1];
            while(pointer_1 < name.size() && name[pointer_1] == ch){
                count_1++;
                pointer_1++;
            }
            while(pointer_2 < typed.size() && typed[pointer_2] == ch){
                count_2++;
                pointer_2++;
            }
            if(count_1 > count_2){
                return false;
            }else{
                count_1 = 0;
                count_2 = 0;
            }
        }
        return pointer_1 == name.size() && pointer_2 == typed.size();
    }
};

// int main(){
//     Solution s;
//     // "alex",  "aaleex"
//     // "saeed", "ssaaedd"
//     cout << s.isLongPressedName("saeed", "ssaaedd") << endl;
//     return 0;
// }
// @lc code=end

