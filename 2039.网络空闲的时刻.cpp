/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
public:
    // 6 5;
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int size = patience.size();
        vector<int> dist(size, 0);
        map<int, vector<int>> m;
        for(int i = 0; i < edges.size(); i++){
            auto it = m.find(edges[i][0]);
            if(it == m.end()){
                m.insert(pair<int, vector<int>>(edges[i][0], {edges[i][1]}));
            }else{
                m[edges[i][0]].push_back(edges[i][1]);
            }
            it = m.find(edges[i][1]);
            if(it == m.end()){
                m.insert(pair<int, vector<int>>(edges[i][1], {edges[i][0]}));
            }else{
                m[edges[i][1]].push_back(edges[i][0]);
            }
        }
        
        queue<vector<int>> q;   // 0:结点编号 1:距0最近距离
        q.push({0, 0});
        while(!q.empty()){
            vector<int> source = q.front();
            q.pop();    // 删除front
            for(auto node : m[source[0]]){
                if(dist[node] == 0){
                    q.push({node, source[1] + 1});
                    dist[node] = source[1] + 1;
                }
            }
        }
        int latest = 0;
        // cout << dist << endl;
        // cout << patience << endl;
        // cout << 0 << ": " << m[0] << endl;
        for(int i = 1; i < size; i++){
            // cout << i << ": " << m[i] << endl;
            int trip = dist[i] * 2;
            int round = trip / patience[i];
            int left = trip % patience[i];
            int late = trip;
            if(round > 0){
                late += trip - (left > 0 ? left : patience[i]);
            }
            latest = max(latest, late);
        }

        return latest + 1;
    }
};
// @lc code=end
int main(){
    Solution s;
    // cout << 1 % 0 << endl;  // division by zero
    // vector<vector<int>> edges = {{0,1}};    // [[0,1]]\n[0,1]
    // vector<int> patience  = {0,1};
    vector<vector<int>> edges = {{0,1},{1,2}};
    vector<int> patience  = {0,2,1};
    // vector<vector<int>> edges = {{0,1},{0,2},{1,2}};
    // vector<int> patience  = {0,10,10};
    cout << s.networkBecomesIdle(edges, patience) << endl;
    return 0;
}
