/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.86%)
 * Likes:    992
 * Dislikes: 0
 * Total Accepted:    519.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 二分折半查找
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int low = 1, high = x/2;
        while(low < high){
            int mid = (low + high) / 2;
            auto y = (unsigned long long)mid * mid;
            if(y == x){
                return mid;
            }else if(y > x){
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        auto y = (unsigned long long)low * low;
        if(y > x){
            return low -1;
        }
        return low;
    }

    int mySqrt1(int x) {
        // cout << (unsigned long long)46341 * 46341 << endl;
        // cout << sqrt(2147483647) << endl;
        // cout << INT_MAX << endl;    // 2147483647
        for(int i = 0; i <= x; ++i){
            auto y = (unsigned long long)i * i;
            if(y == x){
                return i;
            }else if(y > x){
                return i-1;
            }
        }
        return 0;
    }
};
// @lc code=end

