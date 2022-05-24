/*
 * @lc app=leetcode.cn id=832 lang=csharp
 *
 * [832] 翻转图像
 *
 * https://leetcode.cn/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (79.44%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    92.4K
 * Total Submissions: 116.3K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * 给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
 * 
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。
 * 
 * 
 * 例如，水平翻转 [1,1,0] 的结果是 [0,1,1]。
 * 
 * 
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
 * 
 * 
 * 例如，反转 [0,1,1] 的结果是 [1,0,0]。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：image = [[1,1,0],[1,0,1],[0,0,0]]
 * 输出：[[1,0,0],[0,1,0],[1,1,1]]
 * 解释：首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 * ⁠    然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * 输出：[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 解释：首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 * ⁠    然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] == 0 或 1.
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 11 70; 100 81;
    public int[][] FlipAndInvertImage(int[][] image) {
        int size = image.Length;
        for(int i = 0; i < size; ++i){
            int low = 0, high = size - 1;
            while(low < high){
                int tmp = image[i][low];
                image[i][low] = 1-image[i][high];
                image[i][high] = 1-tmp;
                ++low;
                --high;
            }
            if(low == high){
                image[i][high] = 1-image[i][high];
            }
        }
        return image;
    }
}
// @lc code=end

