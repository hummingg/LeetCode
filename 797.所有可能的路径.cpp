/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> g;
    vector<vector<int>> vv;
    vector<int> v;
    int target;
public:
    // 43 81;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        target = g.size() - 1;
        dfs(0);
        return vv;
    }

    void dfs(int i){
        v.push_back(i);
        if(i == target){
            vv.push_back(v);
        }else{
            for(int j = 0; j < g[i].size(); j++){
                dfs(g[i][j]);
            }
        }
        v.pop_back();   // 回溯复原，供同级深度优先遍历
    }
};
// @lc code=end

