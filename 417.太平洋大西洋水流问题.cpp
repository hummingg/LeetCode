/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    39.7K
 * Total Submissions: 77.9K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
 * 
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
 * 上单元格 高于海平面的高度 。
 * 
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 * 
 * 返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向
 * 太平洋和大西洋 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: heights = [[2,1],[1,2]]
 * 输出: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */
#include <iostream>
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
private:
    int m, n;
    vector<bool> flags = {false, false};
    vector<vector<bool>> visited;
    vector<vector<int>> hs, ret;
    vector<vector<int>> drcts = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    // TLE 70/113
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        hs = heights;
        m = hs.size();
        n = hs[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(i, j);   // 暴力
                if(flags[0] && flags[1]){
                    ret.push_back({i, j});
                }
                flags[0] = false;
                flags[1] = false;
                vector<vector<bool>>(m, vector<bool>(n, false)).swap(visited);
            }
        }
        // for(auto v : ret){
        //     cout << v << endl;
        // }
        return ret;
    }

    void dfs(int row, int col){
        visited[row][col] = true;
        // if(row == 0 && col == n-1 || row == m-1 && col == 0){
        //     flags[0] = true;
        //     flags[1] = true;
        //     return;
        // }
        if(row == 0 || col == 0){
            flags[0] = true;
        }
        if(row == m-1 || col == n-1){
            flags[1] = true;
        }
        if(flags[0] && flags[1]){
            return;
        }

        for(auto v : drcts){
            int newRow = row + v[0], newCol = col + v[1];
            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n){
                continue;
            }
            if(!visited[newRow][newCol] && hs[row][col] >= hs[newRow][newCol]){
                dfs(newRow, newCol);    // 能流到这
            }
        }
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<vector<int>> v = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> v = {{2, 1}, {1, 2}};
    s.pacificAtlantic(v);
    // cout << s.pacificAtlantic(v) << endl;
    return 0;
}
