/*
 * @lc app=leetcode.cn id=48 lang=csharp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (74.20%)
 * Likes:    1323
 * Dislikes: 0
 * Total Accepted:    330K
 * Total Submissions: 444.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 77 83; 6 90 176 41.4;
    public void Rotate(int[][] matrix) {
        int size = matrix.Length;
        int n = (size-1) / 2;   // 从内到外的旋转
        for(int i = 0; i <= n; ++i){    // 从外到内旋转 n+1 个墙
            int beginRow = i, endRow = size-1-beginRow;
            int gap = endRow - beginRow;
            for(int rowGap = 0; rowGap < gap; ++rowGap){  // 处理 gap 轮
                // 轮流4次替换，因为二维共4条边
                int dstRow = beginRow, dstCol = beginRow + rowGap;
                int colGap = gap - rowGap;
                int pre = matrix[dstRow][dstCol], tmp = 0;
                // cout << pre << endl;

                dstRow = dstRow + rowGap;
                dstCol = dstCol + colGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;

                dstRow = dstRow + colGap;
                dstCol = dstCol - rowGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;
                
                dstRow = dstRow - rowGap;
                dstCol = dstCol - colGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;

                dstRow = dstRow - colGap;
                dstCol = dstCol + rowGap;
                // tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
            }
        }
    }
}
// @lc code=end

