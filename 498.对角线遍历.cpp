/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (50.27%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    62.2K
 * Total Submissions: 123.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    // 46 100 28 17.1; 90 98 20 17.2;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = 0, col = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ret(m*n);
        int i = 0;
        int direction = 1;  // 列的变化，也是行的反向变化
        while(true){
            if(row < 0){
                if(col < n){
                    row += 1;
                }else{
                    row += 2;
                    col -= 1;
                }
                direction = -direction;
            }else if(row >= m){
                row -= 1;
                col += 2;
                direction = -direction;
            }else if(col < 0){
                col += 1;
                direction = -direction;
            }else if(col >= n){
                row += 2;
                col -= 1;
                direction = -direction;
            }
            ret[i++] = mat[row][col];
            if(row == m-1 && col == n-1){
                break;
            }
            row -= direction;
            col += direction;
        }
        return ret;
    }
};
// @lc code=end
/*
[[1,2,3],[4,5,6],[7,8,9]]\n
[[1,2],[3,4]]\n
[[0]]\n
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]\n
[[1,2,3],[4,5,6]]
*/
