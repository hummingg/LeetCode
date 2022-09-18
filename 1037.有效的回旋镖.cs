/*
 * @lc app=leetcode.cn id=1037 lang=csharp
 *
 * [1037] 有效的回旋镖
 *
 * https://leetcode.cn/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (43.76%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 27.7K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * 给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true
 * 。
 * 
 * 回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：points = [[1,1],[2,3],[3,2]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= xi, yi <= 100
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 62 10;
    public bool IsBoomerang(int[][] points) {
        int x0 = points[0][0], y0 = points[0][1];
        int x1 = points[1][0], y1 = points[1][1];
        int x2 = points[2][0], y2 = points[2][1];
        if(x0 == x1 && y0 == y1 || x0 == x2 && y0 == y2 || x1 == x2 && y1 == y2){
            return false;
        }
        return (y1-y0) * (x2-x0) != (y2-y0) * (x1-x0);
    }
}
// @lc code=end
/*
[[1,1],[2,3],[3,2]]\n
[[1,1],[2,2],[3,3]]\n
[[1,1],[1,1],[3,3]]\n
*/
