#
# @lc app=leetcode.cn id=1260 lang=python3
#
# [1260] 二维网格迁移
#
# https://leetcode.cn/problems/shift-2d-grid/description/
#
# algorithms
# Easy (61.82%)
# Likes:    65
# Dislikes: 0
# Total Accepted:    18.2K
# Total Submissions: 29.4K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
#
# 给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
# 
# 每次「迁移」操作将会引发下述活动：
# 
# 
# 位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
# 位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
# 位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
# 
# 
# 请你返回 k 次迁移操作后最终得到的 二维网格。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
# 输出：[[9,1,2],[3,4,5],[6,7,8]]
# 
# 
# 示例 2：
# 
# 
# 
# 
# 输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
# 输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
# 
# 
# 示例 3：
# 
# 
# 输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
# 输出：[[1,2,3],[4,5,6],[7,8,9]]
# 
# 
# 
# 
# 提示：
# 
# 
# m == grid.length
# n == grid[i].length
# 1 
# 1 
# -1000 
# 0 
# 
# 1 <= m <= 50
# 1 <= n <= 50
# -1000 <= grid[i][j] <= 1000
# 0 <= k <= 100
#

# @lc code=start
class Solution:
    # 107: 71.62%(52ms) 46.29%(15.3MB);
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        k %= m * n
        topK = []
        cnt = 0
        row, col = 0, 0
        for row in range(m-1, -1, -1):
            for col in range(n-1, -1, -1):
                topK.append(grid[row][col])
                cnt += 1
                if cnt == k:
                    break
            if cnt == k:
                break
        col -= 1
        if col == -1:
            row -= 1
            col = n - 1
        idx = m * n - 1 # n*(m-1) + (n-1)
        while row > -1:
            grid[idx // n][idx - idx // n * n] = grid[row][col]
            idx -= 1
            col -= 1
            if col == -1:
                row -= 1
                col = n - 1
        for num in topK:
            grid[idx // n][idx - idx // n * n] = num
            idx -= 1
        return grid
        
    # 方向反了
    def shiftGrid9(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        k %= m * n
        topK = []
        cnt = 0
        row = 0
        col = 0
        for row in range(m):
            for col in range(n):
                topK.append(grid[row][col])
                cnt += 1
                if cnt == k:
                    break
            if cnt == k:
                break
        col += 1
        if col == n:
            row += 1
            col = 0
        cnt = 0
        while row < m:
            grid[cnt // n][cnt - cnt // n * n] = grid[row][col]
            cnt += 1
            col += 1
            if col == n:
                row += 1
                col = 0
        for num in topK:
            grid[cnt // n][cnt - cnt // n * n] = num
            cnt += 1
        return grid
# @lc code=end
'''
[[1,2,3],[4,5,6],[7,8,9]]\n1\n
[[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
[[1,2,3],[4,5,6],[7,8,9]]\n9
'''
