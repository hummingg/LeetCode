using System.Collections.Generic;
using System;
/*
 * @lc app=leetcode.cn id=54 lang=csharp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (48.79%)
 * Likes:    1113
 * Dislikes: 0
 * Total Accepted:    268.9K
 * Total Submissions: 550.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 77 22 128 41.3;
    public IList<int> SpiralOrder(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        int round = (Math.Min(m, n)+ 1) / 2 ;
        int row0, row1, col0, col1; // 上下左右的边界（不含）
        int row, col;
        var ret = new List<int>();
        for(int i = 0; i < round; ++i){
            row0 = i-1;
            row1 = m-i;
            col0 = i-1;
            col1 = n-i;
            row = i;
            col = i;

            // 最后只有 1 行或 1 列的复杂情况
            if(row1 - row0 == 2){
                while(col < col1){
                    ret.Add(matrix[row][col++]);
                }
                break;
            }else if(col1 - col0 == 2){
                while(row < row1){
                    ret.Add(matrix[row++][col]);
                }
                break;
            }

            while(col < col1-1){
                ret.Add(matrix[row][col++]);
            }

            while(row < row1-1){
                ret.Add(matrix[row++][col]);
            }
            
            while(col > col0+1){
                ret.Add(matrix[row][col--]);
            }

            while(row > row0 + 1){
                ret.Add(matrix[row--][col]);
            }
        }
        return ret;
    }

    // WA
    public IList<int> SpiralOrder1(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        int round = (Math.Min(m, n)+ 1) / 2 ;
        // int row0 = -1, row1 = m, col0 = -1, col1 = n;
        int row, col;
        var ret = new List<int>();
        // [0+i,0+i] -> [0+i,n-1-i] -> [m-1-i,n-1-i] -> [m-1-i,0+i] -> [0+i+1,0+i] -new-> [0+i+1,0+i+1]
        for(int i = 0; i < round; ++i){
            // row0 = i-1;
            // row1 = m-i;
            // col0 = i-1;
            // col1 = n-i;
            // 左 -> 右（不含最右）
            // 最左的横、纵坐标相同
            for(col = 0+i; col < n-1-i; ++col){
                // Console.WriteLine($"{matrix[i][col]}");
                ret.Add(matrix[0+i][col]);
            }
            // 最右的横、纵坐标相同，说明就是最左那个
            if(0+i == n-1-i){
                ret.Add(matrix[0+i][col]);
                break;
            }

            // 上 -> 下（不含最下）
            for(row = 0+i; row < m-1-i; ++row){
                // Console.WriteLine($"{matrix[row][n-1-i]}");
                ret.Add(matrix[row][n-1-i]);
            }
            if(0+i == m-1-i){
                ret.Add(matrix[row][n-1-i]);
                break;
            }

            // 右 -> 左
            for(col = n-1-i; col > 0+i; --col){
                // Console.WriteLine($"{matrix[m-1-i][col]}");
                ret.Add(matrix[m-1-i][col]);
            }
            if(n-1-i == 0+i){
                ret.Add(matrix[m-1-i][col]);
                break;
            }

            // 下 -> 上
            for(row = m-1-i; row > 0+i; --row){
                // Console.WriteLine($"{matrix[row][0+i]}");
                ret.Add(matrix[row][0+i]);
            }
            if(m-1-i == 0+i){
                ret.Add(matrix[row][0+i]);
                break;
            }
        }
        return ret;
    }
}
// @lc code=end
/*
[[1,2,3],[4,5,6],[7,8,9]]\n
[[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]\n
[[1,2],[5,6],[9,10]]\n
[[6,9,7]]
*/
