/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 55;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        // 其实就是求 0 ~ n-1 的全排列
        auto vv = recursion(n-1);
        for(int i = 0; i < vv.size(); i++){
            for(int j = 0; j < vv[i].size(); j++){
                vv[i][j] = nums[vv[i][j]];
            }
        }
        return vv;
    }

    // 求 0 ~ n 的全排列
    vector<vector<int>> recursion(int n){
        if(n == 0){
            return {{0}};
        }
        vector<vector<int>> result;
        auto vv = recursion(n-1);
        for(int i = 0; i < vv.size(); i++){
            for(int j = 0; j <= vv[i].size(); j++){
                vv[i].insert(vv[i].begin() + j, n);
                result.push_back(vv[i]);
                vv[i].erase(vv[i].begin() + j);
            }
        }
        return result;
    }
};
// @lc code=end

