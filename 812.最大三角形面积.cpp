/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 *
 * https://leetcode.cn/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (63.13%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 
 * 
 * 示例:
 * 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * 输出: 2
 * 解释: 
 * 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
 * 
 * 
 * 
 * 
 * 注意: 
 * 
 * 
 * 3 <= points.length <= 50.
 * 不存在重复的点。
 * -50 <= points[i][j] <= 50.
 * 结果误差值在 10^-6 以内都认为是正确答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 25 36; 46 45;
    double largestTriangleArea(vector<vector<int>>& points) {
        int size = points.size();
        double maxArea = 0;
        for(int i = 0; i < size-2; ++i){
            for(int j = i+1; j < size-1; ++j){
                for(int k = j+1; k < size; ++k){
                    double edge1 = sqrt(pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2));
                    double edge2 = sqrt(pow(points[i][0]-points[k][0], 2) + pow(points[i][1]-points[k][1], 2));
                    double edge3 = sqrt(pow(points[j][0]-points[k][0], 2) + pow(points[j][1]-points[k][1], 2));
                    double p = (edge1 + edge2 + edge3) / 2;
                    maxArea = max(maxArea, sqrt(p * (p-edge1)* (p-edge2)* (p-edge3)));  // 海伦公式
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

