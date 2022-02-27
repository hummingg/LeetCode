/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 97 20; 61 89;
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowHeight, colHeight;   // 各行最高、各列最高，默认初始化为0
        rowHeight.resize(n, 0);
        colHeight.resize(n, 0);
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] > rowHeight[row]){
                    rowHeight[row] = grid[row][col];
                }
            }
        }
        for(int col = 0; col < n; col++){
            for(int row = 0; row < n; row++){
                if(grid[row][col] > colHeight[col]){
                    colHeight[col] = grid[row][col];
                }
            }
        }

        int sum = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                int minHeight = rowHeight[row] < colHeight[col] ? rowHeight[row] : colHeight[col];
                sum += minHeight - grid[row][col];
            }
        }

        return sum;
    }
};

// int main(){
//     Solution s;
//     // {{0,0,0},{0,0,0},{0,0,0}}
//     // {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}}
//     vector<vector<int>> grid = {{0,0,0},{0,0,0},{0,0,0}};
//     cout << s.maxIncreaseKeepingSkyline(grid) << endl;
//     return 0;
// }
// @lc code=end

