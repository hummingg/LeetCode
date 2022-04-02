/*
 * @lc app=leetcode.cn id=2160 lang=cpp
 *
 * [2160] 拆分数位后四位数字的最小和
 */

// @lc code=start
class Solution {
public:
    // 100 5;
    int minimumSum(int num) {
        vector<int> v;
        do{
            v.push_back(num % 10);
            num = num / 10;
        }while(num>0);
        sort(v.begin(), v.end());
        int num1 = v[0] * 10 + v[2];
        int num2 = v[1] * 10 + v[3];
        return num1 + num2;
    }
};
// @lc code=end

