/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    // 26 12;
    string addStrings(string num1, string num2) {
        string ret = "";
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0, pos = 0, sum = 0, partSum = 0;
        while(i >= 0 && j >= 0){
            partSum = num1[i] - '0' + num2[j] - '0' + carry;
            carry = partSum / 10;
            // sum += (int)pow(10, pos) * (partSum%10);
            ret = string(1, partSum%10 + '0') + ret;
            --i, --j, ++pos;
        }
        while(i >= 0){
            int partSum = num1[i] - '0' + carry;
            carry = partSum / 10;
            // sum += (int)pow(10, pos) * (partSum%10);
            ret = string(1, partSum%10 + '0') + ret;
            --i, ++pos;
        }
        while(j >= 0){
            int partSum = num2[j] - '0' + carry;
            carry = partSum / 10;
            // sum += (int)pow(10, pos) * (partSum%10);
            ret = string(1, partSum%10 + '0') + ret;
            --j, ++pos;
        }
        if(carry == 1){
            ret = string(1, '1') + ret;
        }
        // sum += carry * (int)pow(10, pos);
        // do{
        //     ret = string(1, sum % 10 + '0') + ret;  // char 转 string
        //     sum /= 10;
        // }while(sum > 0);
        return ret;
    }
};
// @lc code=end
/*
""11"\n"123"\n
"456"\n"77"\n
"0"\n"0""
*/
