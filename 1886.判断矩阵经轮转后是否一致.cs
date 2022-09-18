/*
 * @lc app=leetcode.cn id=1886 lang=csharp
 *
 * [1886] 判断矩阵经轮转后是否一致
 *
 * https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
 *
 * algorithms
 * Easy (58.61%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 13.4K
 * Testcase Example:  '[[0,1],[1,0]]\n[[1,0],[0,1]]'
 *
 * 给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat
 * 与 target 一致，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
 * 输出：true
 * 解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
 * 输出：false
 * 解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
 * 输出：true
 * 解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == mat.length == target.length
 * n == mat[i].length == target[i].length
 * 1 
 * mat[i][j] 和 target[i][j] 不是 0 就是 1
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 86 67; 35 5 96 40.3;
    /*
    0:   row,col -> row,col
    90:  row,col -> col,n-1-row
    180: row,col -> n-1-row, n-1-col
    270: row,col -> n-1-col, row
    不是 0 就是 1：异或
    */
    public bool FindRotation(int[][] mat, int[][] target) {
        int n = mat.Length;
        bool dif = false;
        for(int row = 0; row < n && !dif; ++row){
            for(int col = 0; col < n; ++col){
                if((mat[row][col] ^ target[row][col]) == 1){
                    dif = true;
                    break;
                }
            }
        }
        if(!dif){
            return true;
        }
        dif = false;
        for(int row = 0; row < n && !dif; ++row){
            for(int col = 0; col < n; ++col){
                if((mat[row][col] ^ target[col][n-1-row]) == 1){
                    dif = true;
                    break;
                }
            }
        }
        if(!dif){
            return true;
        }
        dif = false;
        for(int row = 0; row < n && !dif; ++row){
            for(int col = 0; col < n; ++col){
                if((mat[row][col] ^ target[n-1-row][n-1-col]) == 1){
                    dif = true;
                    break;
                }
            }
        }
        if(!dif){
            return true;
        }
        dif = false;
        for(int row = 0; row < n && !dif; ++row){ 
            for(int col = 0; col < n; ++col){
                Console.WriteLine($"{mat[row][col]} {target[n-1-col][n-1-row]}");
                if((mat[row][col] ^ target[n-1-col][row]) == 1){
                    dif = true;
                    break;
                }
            }
        }
        
        // 90:  row,col -> col,n-1-row
        //      n-1-col, row  -> row,col
        return !dif;
    }
}
// @lc code=end
/*
[[0,1],[1,0]]\n[[1,0],[0,1]]\n
[[0,1],[1,1]]\n[[1,0],[0,1]]\n
[[0,0,0],[0,1,0],[1,1,1]]\n[[1,1,1],[0,1,0],[0,0,0]]\n
[[1,0],[0,0]]\n[[0,0],[0,1]]\n
[[1,1],[0,1]]\n[[1,1],[1,0]]\n
[[0,0],[1,0]]\n[[1,0],[0,0]]
*/
