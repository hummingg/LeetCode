/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */

// @lc code=start
class Solution {
public:
    // 100 30;
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0];
        int y = points[0][1];
        int count = 0;
        for(int i = 1; i < points.size(); i++){
            int offsetX = points[i][0] - x;
            int offsetY = points[i][1] - y;
            count += min(abs(offsetX), abs(offsetY));
            if(abs(offsetX) <= abs(offsetY)){   // X坐标先达到
                // 方向?
                x = points[i][0];
                if(offsetY >= 0){
                    y += abs(offsetX);
                }else{
                    y -= abs(offsetX);
                }
                count += abs(points[i][1]-y);
                y = points[i][1];
            }else{
                // 方向?
                y = points[i][1];
                if(offsetX >= 0){
                    x += abs(offsetY);
                }else{
                    x -= abs(offsetY);
                }
                count += abs(points[i][0]-x);
                x = points[i][0];
            }
        }
        return count;
    }
};
// @lc code=end

