/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution {
public:
    // 20 73; 81 90;
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
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
};
// @lc code=end

