/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        bool positive = true;
        string result = "";
        
        int i = 0;
        while(i < size && s[i] == ' '){
            i++;
        };
        if(i < size){
            if(s[i] == '-'){
                positive = false;
                i++;
            }else if(s[i] == '+'){
                i++;
            }
        }

        // 连续多个0只保留1个
        while(i < size && s[i] == '0'){
            result[0] = '0';
            i++;
        };
        for(; i < size; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                result += s[i];
                if(result.size() > 11){ // 节省内存
                    break;
                }
            }else{
                break;
            }
        }
        if(result.size() == 0){
            return 0;
        }
        if(result.size() > 11){ // 节省计算
            return positive ? INT_MAX : INT_MIN;
        }

        int sum = 0;
        for(i = 0; i < result.size(); i++){
            int number = result[i] - '0';
            if((INT_MAX - number)/10.0 >= sum ){
                sum = sum * 10 + number;
            }else{  // 溢出，2147483648>2147483647, 也包含在INT_MIN = -2147483648
                return positive ? INT_MAX : INT_MIN;
            }
        }

        return positive ? sum : -sum;
    }

};
// n 1
// @lc code=end

