using System;
using System.Runtime.Serialization;
/*
 * @lc app=leetcode.cn id=812 lang=csharp
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

// int[][] points = new int[][]{new int[]{35,-23},new int[]{-12,-48},new int[]{-34,-40},new int[]{21,-25},new int[]{-35,-44},new int[]{24,1},new int[]{16,-9},new int[]{41,4},new int[]{-36,-49},new int[]{42,-49},new int[]{-37,-20},new int[]{-35,11},new int[]{-2,-36},new int[]{18,21},new int[]{18,8},new int[]{-24,14},new int[]{-23,-11},new int[]{-8,44},new int[]{-19,-3},new int[]{0,-10},new int[]{-21,-4},new int[]{23,18},new int[]{20,11},new int[]{-42,24},new int[]{6,-19}};
// Console.WriteLine(new Solution().LargestTriangleArea(points));
// Test();
// static void Test(){
//     int[,] points = {{35,-23},{-12,-48},{-34,-40},{21,-25},{-35,-44},{24,1},{16,-9},{41,4},{-36,-49},{42,-49},{-37,-20},{-35,11},{-2,-36},{18,21},{18,8},{-24,14},{-23,-11},{-8,44},{-19,-3},{0,-10},{-21,-4},{23,18},{20,11},{-42,24},{6,-19}};
//     Console.WriteLine(new Solution().LargestTriangleArea(points));
//     Console.WriteLine("Test");
// }
// @lc code=start
public class Solution {
    // 麻烦
    public double LargestTriangleArea9(int[][] points) {
        int size = points.Length;
        double maxArea = 0;
        for(int i = 0; i < size-2; ++i){
            for(int j = i+1; j < size-1; ++j){
                for(int k = j+1; k < size; ++k){
                    int x1 = Math.Max(points[i][0], points[j][0]);
                    x1 = Math.Max(x1, points[k][0]);
                    int y1 = Math.Max(points[i][1], points[j][1]);
                    y1 = Math.Max(y1, points[k][1]);
                    int x2 = Math.Min(points[i][0], points[j][0]);
                    x2 = Math.Min(x2, points[k][0]);
                    int y2 = Math.Min(points[i][1], points[j][1]);
                    y2 = Math.Min(y2, points[k][1]);
                    int dx1 = Math.Abs(points[i][0]-points[j][0]);
                    int dy1 = Math.Abs(points[i][1]-points[j][1]);
                    int dx2 = Math.Abs(points[i][0]-points[k][0]);
                    int dy2 = Math.Abs(points[i][1]-points[k][1]);
                    int dx3 = Math.Abs(points[j][0]-points[k][0]);
                    int dy3 = Math.Abs(points[j][1]-points[k][1]);
                    double area = (x1-x2) * (y1-y2) - 1.0 / 2 * (dx1 * dy1 + dx2 * dy2 + dx3 * dy3);
                    int[] borders = {x1, x2, y1, y2};
                    if(area == 18.5){
                        Console.WriteLine(i + " " + j + " " + k);
                    }
                    int mid = -1;
                    if(Array.IndexOf(borders, points[i][0]) == -1 && Array.IndexOf(borders, points[i][0]) == -1){
                        mid = i;
                    }else if(Array.IndexOf(borders, points[j][0]) == -1 && Array.IndexOf(borders, points[j][0]) == -1){
                        mid = j;
                    }else if(Array.IndexOf(borders, points[k][0]) == -1 && Array.IndexOf(borders, points[k][0]) == -1){
                        mid = k;
                    }
                    if(mid != -1){
                        area -= (points[mid][0] - x2) * (points[mid][1] - x2); // 错误
                    }
                    maxArea = Math.Max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    // 9 22; 6 6;
    public double LargestTriangleArea(int[][] points) {
        // int[][] point = {{35,-23},{-12,-48},{-34,-40},{21,-25},{-35,-44},{24,1},{16,-9},{41,4},{-36,-49},{42,-49},{-37,-20},{-35,11},{-2,-36},{18,21},{18,8},{-24,14},{-23,-11},{-8,44},{-19,-3},{0,-10},{-21,-4},{23,18},{20,11},{-42,24},{6,-19}};
        int size = points.Length;
        double maxArea = 0;
        for(int i = 0; i < size-2; ++i){
            for(int j = i+1; j < size-1; ++j){
                for(int k = j+1; k < size; ++k){
                    // Math.Sqrt 报 NaN
                    // double edge1 = Math.Sqrt((points[i][0]-points[j][0]) * (points[i][0]-points[j][0]) + (points[i][1]-points[j][1]) * (points[i][1]-points[j][1]));
                    // double edge2 = Math.Sqrt((points[i][0]-points[k][0]) * (points[i][0]-points[k][0]) + (points[i][1]-points[k][1]) * (points[i][1]-points[k][1]));
                    // double edge3 = Math.Sqrt((points[k][0]-points[j][0]) * (points[k][0]-points[j][0]) + (points[k][1]-points[j][1]) * (points[k][1]-points[j][1]));
                    
                    double edge1 = Math.Sqrt(Math.Pow(points[i][0]-points[j][0], 2) + Math.Pow(points[i][1]-points[j][1], 2));
                    double edge2 = Math.Sqrt(Math.Pow(points[i][0]-points[k][0], 2) + Math.Pow(points[i][1]-points[k][1], 2));
                    double edge3 = Math.Sqrt(Math.Pow(points[k][0]-points[j][0], 2) + Math.Pow(points[k][1]-points[j][1], 2));
                    
                    double p = (edge1 + edge2 + edge3) / 2;
                    maxArea = Math.Max(maxArea, Math.Sqrt(Math.Abs(p * (p-edge1) * (p-edge2) * (p-edge3))));    // 注意 Math.Abs
                }
            }
        }
        return maxArea;
    }
}
// @lc code=end
/*
[[2,5],[7,7],[10,8],[10,10],[1,1]]
*/

