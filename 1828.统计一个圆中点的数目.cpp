/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 76 42;
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> pointNums(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++){
            int centerX = queries[i][0];
            int centerY = queries[i][1];
            int round = queries[i][2];
            for(int j = 0; j < points.size(); j++){
                int x = points[j][0];
                int y = points[j][1];
                if((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= round * round){
                    pointNums[i]++;
                }
            }
        }
        return pointNums;
    }
};
// points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
// points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
// @lc code=end

