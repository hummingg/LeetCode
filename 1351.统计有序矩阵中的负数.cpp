/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
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
public:
    // 86 98;99 39;
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = 0, col = n-1;
        while(row < m && col >= 0){
            if(grid[row][col] >= 0){
                ++row;
            }else{  // 找到该列第一个负数
                count += m-row;
                --col;
            }
        }
        return count;
    }
    // 86 64; 41 79;
    int countNegatives3(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = 0, col = n-1;
        while(row < m && col >= 0){
            if(grid[row][col] >= 0){    // 找到该行第一个非负数
                count += n-1 - col;
                ++row;
            }else{
                --col;
            }
            
        }
        if(col == -1){
            count += n;
        }
        if(row < m)
            count += (m-1 - row) * n;
        return count;
    }
    // 8 86; 86 26; 9 79; 86 74;
    // 进阶? O(m+n)
    int countNegatives2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return recur(grid, 0, 0, m-1, n-1);
    }

    int recur(vector<vector<int>>& grid, int a, int b, int x, int y){
        if(a > x || b > y){
            return 0;
        }
        int i = x, j = y;
        bool stop = false;
        while(i >= a && j >= b && !stop){
            if(grid[i][j] < 0){
                --i;
                --j;
                continue;
            }
            stop = true;
        }
        int count = (x-i) * (y-j); // i,j -> x,y
        count += recur(grid, i+1, b, x, j);
        count += recur(grid, a, j+1, i, y);
        return count;
    }
    
    // 41 70;
    int countNegatives1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] < 0){
                    count += n - j;
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    // vector<vector<int>> vvi = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    vector<vector<int>> vvi = {{3,2},{1,0}};
    cout << s.countNegatives(vvi) << endl;
    return 0;
}
/*
[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
*/