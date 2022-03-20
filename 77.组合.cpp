/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int target;
    vector<int> v;
    vector<vector<int>> vv;
public:
    // 16 59;
    // 从小到大依次求得
    vector<vector<int>> combine(int n, int k) {
        target = n;
        recur(1, k);
        return vv;
    }

    // base: >=此数 k: 凑k个数
    void recur(int base, int k){
        if(base > target && k > 0){
            return;
        }
        if(k == 0){
            vv.push_back(v);
            return;
        }
        for(int i = base; i <= target; i++){
            v.push_back(i);
            recur(i+1, k-1);    // 递归
            v.pop_back();   // 回溯
        }
    }
};
// @lc code=end

