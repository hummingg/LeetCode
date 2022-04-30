/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> grid;
    int m, n;
public:
    // 可以再试试动态规划
    // 17 39;
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vvi(m, vector<int>(n)); // 扩展
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += grid[0][i];
            vvi[0][i] = sum;
        }
        sum = 0;
        for(int i = 0; i < m; ++i){
            sum += grid[i][0];
            vvi[i][0] = sum;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                vvi[i][j] = min(vvi[i-1][j], vvi[i][j-1]) + grid[i][j];
            }
        }
        return vvi[m-1][n-1];
    }

    // 递归 Time Limit Exceeded 23/61
    int minPathSum1(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        return minSubPathSum(0, 0, 0);
    }

    int minSubPathSum(int row, int col, int sum){
        if(row >= m || col >= n){
            // cout << "结束：" << sum << endl;
            return INT_MAX;
        }
        // cout << grid[row][col] << endl;
        sum += grid[row][col];
        if(row == m-1 && col == n-1){
            return sum;
        }
        return min(minSubPathSum(row+1, col, sum), minSubPathSum(row, col+1, sum));
    }
};
// @lc code=end
/*
[[1,3,1],[1,5,1],[4,2,1]]\n
[[1,2,3],[4,5,6]]
*/
