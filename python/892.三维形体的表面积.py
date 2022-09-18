#
# @lc app=leetcode.cn id=892 lang=python3
#
# [892] 三维形体的表面积
#
# https://leetcode.cn/problems/surface-area-of-3d-shapes/description/
#
# algorithms
# Easy (64.03%)
# Likes:    162
# Dislikes: 0
# Total Accepted:    36.2K
# Total Submissions: 56.5K
# Testcase Example:  '[[1,2],[3,4]]'
#
# 给你一个 n * n 的网格 grid ，上面放置着一些 1 x 1 x 1 的正方体。每个值 v = grid[i][j] 表示 v
# 个正方体叠放在对应单元格 (i, j) 上。
# 
# 放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。
# 
# 请你返回最终这些形体的总表面积。
# 
# 注意：每个形体的底面也需要计入表面积中。
# 
# 
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：grid = [[1,2],[3,4]]
# 输出：34
# 
# 
# 示例 2：
# 
# 
# 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
# 输出：32
# 
# 
# 示例 3：
# 
# 
# 输入：grid = [[2,2,2],[2,1,2],[2,2,2]]
# 输出：46
# 
# 
# 
# 
# 提示：
# 
# 
# n == grid.length
# n == grid[i].length
# 1 <= n <= 50
# 0 <= grid[i][j] <= 50
# 
# 
#

# @lc code=start
class Solution:
    # 90: 61.98%(60ms) 5.73%(15.2MB);
    def surfaceArea(self, grid: List[List[int]]) -> int:
        # 10 * 6 - 2*(1+2+1+3) - 2*(0+1+2+3) = 34
        ret = 0
        n = len(grid)
        grid.insert(0, [0]* n)
        for i in range(n+1):
            grid[i].insert(0, 0)
        for i in range(1, n+1):
            for j in range(1, n+1):
                ret += grid[i][j] * 6 - max(0, grid[i][j]-1)*2
                ret -= 2 * (min(grid[i-1][j], grid[i][j]) + min(grid[i][j-1], grid[i][j]))
        return ret
# @lc code=end

