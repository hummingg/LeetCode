/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
    // 100 97;
public:
    int sumOfUnique(vector<int>& nums) {
        const int N = 100 + 1;
        int a[N]{};
        for(int i = 0; i < nums.size(); ++i){
            ++a[nums[i]];
        }
        int sum = 0;
        for(int i = 1; i < N; ++i){
            if(a[i] == 1){
                sum += i;
            }
        }
        return sum;
    }
};
// @lc code=end

