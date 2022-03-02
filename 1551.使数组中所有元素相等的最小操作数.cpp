/*
 * @lc app=leetcode.cn id=1551 lang=cpp
 *
 * [1551] 使数组中所有元素相等的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        // 1 3 ... 2n-1   平均值为 n
        // int sum = 0;
        // for(int i = 0; i < n/2; i++){
        //     sum += n - (2 * i + 1);
        // }
        // return sum;
        if(n % 2 == 0){
            return (n * n) / 4;
        }else{
            return (n * n - 1) / 4;
        }
    }
};
// @lc code=end

