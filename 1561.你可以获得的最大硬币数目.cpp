/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    // 7 38;
    int maxCoins(vector<int>& piles) {
        int sum = 0;
        int n = piles.size() / 3 ;
        sort(piles.rbegin(), piles.rend()); // 逆序
        for(int i = 0; i < n; i++){
            sum += piles[2 * i + 1];
        }
        return sum;
    }
};
// @lc code=end

