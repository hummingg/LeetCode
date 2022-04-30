/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
public:
    // 34 81;
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDis = INT_MAX;
        int ret = -1;
        for(int i = 0; i < points.size(); ++i){
            int dis = INT_MAX;
            if(x == points[i][0]){
                dis = abs(y - points[i][1]);
            }else if(y == points[i][1]){
                dis = abs(x - points[i][0]);
            }
            if(minDis > dis){
                ret = i;
                minDis = dis;
            }
        }
        return ret;
    }
};
// @lc code=end
/*
3\n4\n[[1,2],[3,1],[2,4],[2,3],[4,4]]\n
3\n4\n[[3,4]]\n
3\n4\n[[2,3]]
*/
