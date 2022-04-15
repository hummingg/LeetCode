/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
public:
    // 100 72;
    int numberOfSteps(int num) {
        int count = 0;
        while(num > 0){
            count++;
            if(num%2 == 1){
                num--;
            }else{
                num /= 2;
            }
        }
        return count;
    }
};
// @lc code=end

