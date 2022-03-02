/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 *
 * [1877] 数组中最大数对和的最小值
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int minSum = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = nums.size()-1; i < j; i++, j--){
            int sum = nums[i] + nums[j];
            minSum = sum > minSum ? sum : minSum;
        }
        return minSum;
    }
};
// @lc code=end

