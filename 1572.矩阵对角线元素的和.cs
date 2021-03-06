/*
 * @lc app=leetcode.cn id=1572 lang=csharp
 *
 * [1572] 矩阵对角线元素的和
 *
 * https://leetcode-cn.com/problems/matrix-diagonal-sum/description/
 *
 * algorithms
 * Easy (80.52%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 32.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
 * 
 * 请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
 * 
 * 
 * 
 * 示例  1：
 * 
 * 
 * 
 * 
 * 输入：mat = [[1,2,3],
 * [4,5,6],
 * [7,8,9]]
 * 输出：25
 * 解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
 * 请注意，元素 mat[1][1] = 5 只会被计算一次。
 * 
 * 
 * 示例  2：
 * 
 * 
 * 输入：mat = [[1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1]]
 * 输出：8
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：mat = [[5]]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == mat.length == mat[i].length
 * 1 <= n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 26 62; 85 80;
    public int DiagonalSum(int[][] mat) {
        int size = mat.Length;
        int sum = 0;
        for(int i = 0; i < size; ++i){
            sum += mat[i][i];
            sum += mat[i][size-1-i];
        }
        if(size % 2 == 1){
            int center = size / 2;
            sum -= mat[center][center];
        }
        return sum;
    }
}
// @lc code=end

