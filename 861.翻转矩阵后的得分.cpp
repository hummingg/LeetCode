/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 57 52;
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 每行首位必须为 1
        for(int row = 0; row < rows; row++){
            if(grid[row][0] == 0){
                for(int col = 0; col < cols; col++){
                    grid[row][col] = 1 - grid[row][col];
                }
            }
        }

        // 每列使 1 至少一半
        for(int col = 1; col < cols; col++){
            int count = 0;
            for(int row = 0; row < rows; row++){
                if(grid[row][col] == 1){
                    count++;
                }
            }
            if(count < (rows+1)/2){
                for(int row = 0; row < rows; row++){
                    grid[row][col] = 1 - grid[row][col];
                }
            }
        }
        
        // 逐行求和
        int sum = 0;
        for(int row = 0; row < rows; row++){
            int num = 0;
            for(int col = 0; col < cols; col++){
                // cout << "grid: " << grid[row][col] << endl;
                num = (num << 1) + grid[row][col];  // 注意运算符优先级
            }
            // cout << "num: " << num << endl;
            sum += num;
        }
        return sum;
    }
};
// @lc code=end

