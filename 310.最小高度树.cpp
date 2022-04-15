/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <climits>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
template <class T> std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
private:
    vector<bool> visited;   // 结点被访问
    int minHeight = INT_MAX;
    int treeHeight = INT_MIN;
    // vector<vector<int>> edges;
    map<int, set<int>> links;
public:
    // TLE63/71
    // 代码的height比题目大1
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // n个结点的树有n-1条边
        for(int i = 0; i < edges.size(); ++i){
            links[edges[i][0]].insert(edges[i][1]);
            links[edges[i][1]].insert(edges[i][0]);
        }
        // for(const auto &[k,v] : links){
        //     cout << k << " " << v << endl;
        // }
        visited.resize(n, false);
        vector<int> labels;
        for(int i = 0; i < n; ++i){
            int height = dfs(i, 1); // 等于 treeHeight
            // cout << height << endl;
            if(height < minHeight){
                minHeight = height;
                labels.clear();
                labels.push_back(i);
            }else if(height == minHeight){
                labels.push_back(i);
            }
            treeHeight = INT_MIN;
            // visited.resize(n, false);
            vector<bool>(n, false).swap(visited); // 匿名类空间被释放
            // vector<int>(v).swap(v);	//v是容器变量
            // visited.assign(n, false);
            // cout << visited[0] << visited[n-1] << endl;
        }
        return labels;
    }

    int dfs(int label, int height){
        // cout << label << " " << height << endl;
        visited[label] = true;
        treeHeight = max(treeHeight, height);
        // set<int> adjs = links[label];
        for(auto node : links[label]){
            if(!visited[node]){ // 退出递归的条件
                // treeHeight = max(treeHeight, dfs(node, height+1));
                dfs(node, height+1);
            }else{
                // treeHeight = max(treeHeight, height);
            }
            // visited[node] = false;  // 回溯？树，不是图，不需要
        }
        return treeHeight;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    vector<vector<int>> vvi = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    cout << s.findMinHeightTrees(6, vvi) << endl;
    return 0;
}
