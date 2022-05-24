using System;
/*
 * @lc app=leetcode.cn id=566 lang=csharp
 *
 * [566] 重塑矩阵
 *
 * https://leetcode-cn.com/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (66.63%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    102.8K
 * Total Submissions: 154.3K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x
 * c）的新矩阵，但保留其原始数据。
 * 
 * 给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
 * 
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
 * 
 * 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]], r = 1, c = 4
 * 输出：[[1,2,3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]], r = 2, c = 4
 * 输出：[[1,2],[3,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * -1000 <= mat[i][j] <= 1000
 * 1 <= r, c <= 300
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 26 53; 73 78;
    public int[][] MatrixReshape(int[][] mat, int r, int c) {
        int m = mat.Length;
        int n = mat[0].Length;
        // if(m * n < r * c || m == r && n == c){   // 理解错误
        if(m * n != r * c || m == r && n == c){
            return mat;
        }
        var ret = new int[r][]; // 挺麻烦
        int row = 0, col = 0;
        ret[row] = new int[c];  // 挺麻烦
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ret[row][col] = mat[i][j];
                ++col;
                if(col == c){
                    ++row;
                    col = 0;
                    if(row < r){
                        ret[row] = new int[c];  // 挺麻烦
                    }
                }
            }
        }
        return ret;
    }
}
// @lc code=end

