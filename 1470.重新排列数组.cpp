/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 26 9;
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < n; i++){
            nums.insert(nums.begin()+ 2*i +1, nums[2 * i+n]);   // 动态插入
        }
        nums.erase(nums.begin()+ 2*n, nums.end());
        return nums;
    }
};
// @lc code=end

