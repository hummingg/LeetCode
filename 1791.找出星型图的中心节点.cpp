/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = 0;
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
            return edges[0][0];
        }else{
            return edges[0][1];
        }
    }
};
// @lc code=end

