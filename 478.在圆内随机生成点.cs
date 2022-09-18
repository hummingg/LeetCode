/*
 * @lc app=leetcode.cn id=478 lang=csharp
 *
 * [478] 在圆内随机生成点
 *
 * https://leetcode.cn/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 20.5K
 * Testcase Example:  '["Solution","randPoint","randPoint","randPoint"]\n[[1.0,0.0,0.0],[],[],[]]'
 *
 * 给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。
 * 
 * 实现 Solution 类:
 * 
 * 
 * Solution(double radius, double x_center, double y_center) 用圆的半径 radius
 * 和圆心的位置 (x_center, y_center) 初始化对象
 * randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: 
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[1.0, 0.0, 0.0], [], [], []]
 * 输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
 * 解释:
 * Solution solution = new Solution(1.0, 0.0, 0.0);
 * solution.randPoint ();//返回[-0.02493，-0.38077]
 * solution.randPoint ();//返回[0.82314,0.38945]
 * solution.randPoint ();//返回[0.36572,0.17248]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 < radius <= 10^8
 * -10^7 <= x_center, y_center <= 10^7
 * randPoint 最多被调用 3 * 10^4 次
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 13 100;
    // 不均匀
    double radius, x_center, y_center;
    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    public double[] RandPoint() {
        double gap = 1e-12;
        var rand = new Random();
        double x = rand.NextDouble() * ( 2 *radius + gap ) - radius;
        double y = rand.NextDouble() * ( 2 *radius + gap ) - radius;
        Console.WriteLine($"{x} {y}");
        while(x * x + y * y > radius * radius){
            while(x < -radius || x > radius){
                x = rand.NextDouble() * ( 2 *radius + gap ) - radius;
            }
            while(y < -radius || y > radius){
                y = rand.NextDouble() * ( 2 *radius + gap ) - radius;
            }
        }
        return new double[2]{x_center + x, y_center + y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.RandPoint();
 */
// @lc code=end

