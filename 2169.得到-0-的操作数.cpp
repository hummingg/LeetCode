/*
 * @lc app=leetcode.cn id=2169 lang=cpp
 *
 * [2169] 得到 0 的操作数
 */

// @lc code=start
class Solution {
    // 100 100 0 5.6;
public:
    int countOperations(int num1, int num2) {
        int count = 0, k = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 >= num2){
                k = num1 / num2;
                num1 -= num2 * k;
            }else{
                k = num2 / num1;
                num2 -= num1 * k;
            }
            count += k;
        }
        return count;
    }
};
// @lc code=end
/*
2\n3
10\n10
*/
