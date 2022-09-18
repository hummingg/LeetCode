/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> flags(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                // 左 和 上。万一有多个左上角？必须使用标记位？
                // if(grid[i][j] == '1' && !flags[i][j] && (i == 0 || grid[i-1][j] == '0') && (j == 0 || grid[i][j-1] == '0')){
                //     ++count;
                // }
                if(grid[i][j] == '1'){
                    if(!flags[i][j]){   // 新的岛屿出现？要检查右边
                        bool newIsland = true;
                        if(i + 1 < m){
                            // if(flags[i+1][j] && grid[i+1][j] == '1'){
                            //    newIsland = false; 
                            // }
                            flags[i+1][j] = true;
                        }
                        if(j + 1 < n){
                            if(flags[i][j+1] && grid[i+1][j] == '1'){
                               newIsland = false; 
                            }
                            flags[i][j+1] = true;
                        }
                        if(newIsland){
                            ++count;
                        }
                    }else{  // 向右下吞噬相连的陆地, 因为是从左上开始遍历
                        if(i + 1 < m){
                            flags[i+1][j] = true;
                        }
                        if(j + 1 < n){
                            flags[i][j+1] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end
/*
[['0','1','1','1','0'],['1','1','0','1','1'],['1','1','0','1','1'],['0','1','1','1','0']]

[
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]\n
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]\n
[["0","1","1","1","0"],["1","1","0","1","1"],["1","1","0","1","1"],["0","1","1","1","0"]]

[
['0','1','1','1','0'],
['1','1','0','1','1'],
['1','1','0','1','1'],
['0','1','1','1','0']]
*/
