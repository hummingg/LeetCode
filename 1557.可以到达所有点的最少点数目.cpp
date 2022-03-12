/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 93 97;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v;
        bool flags[n];
        for(int i = 0; i < n; i++){
            flags[i] = false;
        }
        for(auto it = edges.begin(); it != edges.end(); it++){
            flags[(*it)[1]] = true;
        }
        for(int i = 0; i < n; i++){
            if(!flags[i]){
                v.push_back(i);
            }
        }
        return v;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1}};
    vector<int> v=s.findSmallestSetOfVertices(5, edges);
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}
// @lc code=end

