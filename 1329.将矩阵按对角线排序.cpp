/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 65;
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v;
        int m = mat.size();
        int n = mat[0].size();
        // cout << m << " " << n << endl;
        
        // 固定列0
        for(int i = m-2; i >=0; i--){
            int row = i;
            int col = 0;
            while(row < m && col < n){
                v.push_back(mat[row++][col++]);
            }
            sort(v.begin(), v.end());
            row = i;
            col = 0;
            while(row < m && col < n){
                // cout << v[col] << " ";
                mat[row++][col++] = v[col];
            }
            // cout << endl;
            v.clear();
        }
        // 固定行0
        for(int i = 1; i<n-1; i++){
            // cout << i << endl;
            int row = 0;
            int col = i;
            while(row < m && col < n){
                // cout << mat[row][col] << " ";
                v.push_back(mat[row++][col++]);
            }
            // cout << endl;
            sort(v.begin(), v.end());
            // cout << "size " << v.size() << endl;
            row = 0;
            col = i;
            while(row < m && col < n){
                // cout << v[row] << " ";
                // mat[row][col] = v[row]; // !!!
                // col++;
                // row++;
                mat[row++][col++] = v[row]; // 从右到左
            }
            // cout << endl;
            v.clear();
        }
        return mat;
    }
};

// int main(){
//     Solution s;
//     vector<vector<int>> v = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
//     s.diagonalSort(v);
//     // cout << s.diagonalSort(v) << endl;
//     return 0;
// }
// @lc code=end

