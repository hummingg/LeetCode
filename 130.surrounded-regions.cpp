MyDebug: 130
MyDebug: 3
MyDebug: 1
MyDebug: 3
MyDebug: 0
MyDebug: cache.getProblems function(e, problems) {
    if (e) return cb(e);

    problems.forEach(function(problem) {
      var id = String(problem.id);
      if (id in COMPONIES) {
        problem.companies = (problem.companies || []).concat(COMPONIES[id]);
      }
      if (id in TAGS) {
        problem.tags = (problem.tags || []).concat(TAGS[id]);
      }
    });
    return cb(null, problems);
  } function
MyDebug: keyword = *130*number
MyDebug: problem0 = *195*string
MyDebug: problem = [object Object]
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (45.78%)
 * Total Accepted:    184.4K
 * Total Submissions: 402.9K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X'
 * 填充。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 
 * board[i][j] 为 'X' 或 'O'
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {

    }
};

