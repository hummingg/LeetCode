/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <climits>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648){   // INT_MIN
            return 0;   // 肯定溢出
        }
        bool positive = x > 0;

        int sum = 0;
        int low = 0;
        x = positive ? x : -x;
        
        do{
            low = x % 10; // 放前面不会被覆盖
            if((2147483647 - low) / 10.0 < sum){   // INT_MAX提前检查溢出。正数都溢出那负数肯定溢出。
                return 0;
            }else{
                sum = sum * 10 + low;
            }
            x = x / 10;
        }while(x != 0);

        return positive ? sum : -sum; // 提前检查溢出。正数没溢出那负数肯定没溢出。
    }
};
// @lc code=end

