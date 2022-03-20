/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 76;
    vector<vector<int>> generateMatrix(int n) {
        int row1 = -1, row2 = n, col1 = -1, col2 = n;
        vector<int> v;
        v.resize(n);
        vector<vector<int>> matrix;
        matrix.resize(n, v);

        // vector<vector<int> > matrix;
        // matrix.resize(n);//行数为m
        // for(int i=0;i<n;i++)//每行列数为n
        //     matrix[i].resize(n);

        // matrix[0][0]=0;
        // cout << matrix[1][1] << endl;

        int row = 0, col = 0;
        int count = 1, direction = 0;
        while(count <= n*n){
            switch (direction)
            {
                case 0:// 左右
                    // cout << count << "\t";
                    matrix[row][col++] = count++;
                    // cout << count << "\t";
                    if(col == col2){
                        direction = 1;
                        col--;
                        col2--; // 右上角更新边界
                        row1++;
                        row++;
                    }
                    break;
                case 1:// 上下
                    // cout << count << "\t";
                    matrix[row++][col] = count++;
                    if(row == row2){
                        direction = 2;
                        row--;
                        // row2--;
                        col--;
                    }
                    break;
                case 2:// 右左
                    // cout << count << "\t";
                    matrix[row][col--] = count++;
                    if(col == col1){
                        direction = 3;
                        col++;
                        col1++; // 左下角更新边界
                        row2--;
                        row--;
                    }
                    break;
                case 3:// 下上
                    // cout << count << "\t";
                    matrix[row--][col] = count++;
                    if(row == row1){
                        direction = 0;
                        row++;
                        // row1++;
                        col++;
                    }
                    break;
                default:
                    break;
            }
        }
        return matrix;
    }
};
// @lc code=end

// int main(){
//     Solution s;
//     s.generateMatrix(3);
//     // cout << s.generateMatrix(3) << endl;
//     return 0;
// }
