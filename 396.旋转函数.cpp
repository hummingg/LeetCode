/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    // 84 98;
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int baseFunc = 0;
        for(int i = 1; i < size; ++i){
            baseFunc += i * nums[i];
        }
        // cout << baseFunc << endl;
        int maxFunc = baseFunc;
        for(int i = 1; i < size; ++i){
            baseFunc += sum - size * nums[size-i];    // 绝
            maxFunc = max(maxFunc, baseFunc);
            // cout << baseFunc << endl;
        }
        return maxFunc;
    }
};
// @lc code=end

