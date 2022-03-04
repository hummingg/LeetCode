/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 62;
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int n = 1 << size;  // 子集个数
        vector<vector<int>> vv;
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(int j = 0; j < size; j++){
                if(((i >> (size-j-1)) % 2) == 1){ // n=8=111 对应0 1 2
                    v.push_back(nums[j]);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
};
// @lc code=end

