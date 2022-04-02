/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    // 100 71;
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i = left; i <= right; ++i){
            int n = i;
            while(n > 0){
                int num =  n % 10;
                if(num == 0 || i % num != 0){
                    break;
                }
                n /= 10;
            }
            if(n == 0){
                v.push_back(i);
            }
        }
        return v;
    }
};
// @lc code=end

