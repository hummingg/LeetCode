#
# @lc app=leetcode.cn id=827 lang=python3
#
# [827] 最大人工岛
#
# https://leetcode.cn/problems/making-a-large-island/description/
#
# algorithms
# Hard (39.56%)
# Likes:    187
# Dislikes: 0
# Total Accepted:    16.4K
# Total Submissions: 41.3K
# Testcase Example:  '[[1,0],[0,1]]'
#
# 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
# 
# 返回执行此操作后，grid 中最大的岛屿面积是多少？
# 
# 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
# 
# 
# 
# 示例 1:
# 
# 
# 输入: grid = [[1, 0], [0, 1]]
# 输出: 3
# 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
# 
# 
# 示例 2:
# 
# 
# 输入: grid = [[1, 1], [1, 0]]
# 输出: 4
# 解释: 将一格0变成1，岛屿的面积扩大为 4。
# 
# 示例 3:
# 
# 
# 输入: grid = [[1, 1], [1, 1]]
# 输出: 4
# 解释: 没有0可以让我们变成1，面积依然为 4。
# 
# 
# 
# 提示：
# 
# 
# n == grid.length
# n == grid[i].length
# 1 
# grid[i][j] 为 0 或 1
# 
# 
#

# @lc code=start
class Solution:
    # 75: 30.38%(2172ms) 55.27%(24.7MB);
    def __init__(self):
        self.group_id = 2   # ID
        self.group_cnt = 0
        self.grid = []
        self.n = 0
        self.visited = []
        self.id2cnt = {0: 0}
        
    def largestIsland(self, grid: List[List[int]]) -> int:
        '''
            图的遍历。
            求出图的所有连通分量的结点（岛屿）数，每个连图分量分配一个ID，根据ID查询该连图分量的大小。
            将grid的每个1改成所属的连通分量ID，ID从2开始（便于区分）。
        '''
        self.grid = grid
        self.n = len(grid)
        self.visited = [[False] * self.n for _ in range(self.n)]    # 注意！
        for r in range(self.n):
            for c in range(self.n):
                if self.grid[r][c] == 0 or self.visited[r][c]:
                    continue
                self.dfs(r, c)
                self.id2cnt[self.group_id] = self.group_cnt
                self.group_cnt = 0
                self.group_id += 1
        # print(self.grid, self.visited)
        ret = max(self.id2cnt.values())
        for r in range(self.n):
            for c in range(self.n):
                if self.grid[r][c] != 0:
                    continue
                st = set()
                for ver, hor in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                    row = r + ver
                    col = c + hor
                    if row < 0 or row >= self.n or col < 0 or col >= self.n:
                        continue
                    st.add(self.grid[row][col]) # ID
                cur = 1
                for id in st:
                    cur += self.id2cnt[id]
                ret = max(ret, cur)
        return ret
        
    def dfs(self, row: int, col: int):
        if row < 0 or row >= self.n or col < 0 or col >= self.n \
            or self.grid[row][col] == 0 or self.visited[row][col]:
            return
        self.visited[row][col] = True
        self.grid[row][col] = self.group_id
        self.group_cnt += 1
        for ver, hor in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            r = row + ver
            c = col + hor
            self.dfs(r, c)
# @lc code=end
'''
[[1, 0], [0, 1]]\n
[[1, 1], [1, 0]]\n
[[1, 1], [1, 1]]\n
'''
