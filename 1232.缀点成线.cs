/*
 * @lc app=leetcode.cn id=1232 lang=csharp
 *
 * [1232] 缀点成线
 *
 * https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (46.46%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 83.5K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * 给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y
 * 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates 中不含重复的点
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 83 67;
    public bool CheckStraightLine(int[][] coordinates) {
        int size = coordinates.Length;
        if(size < 3){
            return true;
        }
        // (y1-y0)/(x1-x0) = (yi-y0)/(xi-x0)
        // (y1-y0)(xi-x0) = (yi-y0)(x1-x0)
        int y10 = coordinates[1][1]-coordinates[0][1];
        int x10 = coordinates[1][0]-coordinates[0][0];
        for(int i = 2; i < size; ++i){
            int yi0 = coordinates[i][1]-coordinates[0][1];
            int xi0 = coordinates[i][0]-coordinates[0][0];
            if(y10 * xi0 != yi0 * x10){
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

