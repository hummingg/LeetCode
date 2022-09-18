#
# @lc app=leetcode.cn id=1030 lang=python3
#
# [1030] 距离顺序排列矩阵单元格
#
# https://leetcode.cn/problems/matrix-cells-in-distance-order/description/
#
# algorithms
# Easy (70.89%)
# Likes:    130
# Dislikes: 0
# Total Accepted:    44.2K
# Total Submissions: 62.3K
# Testcase Example:  '1\n2\n0\n0'
#
# 给定四个整数 row ,   cols ,  rCenter 和 cCenter 。有一个 rows x cols 的矩阵，你在单元格上的坐标是
# (rCenter, cCenter) 。
# 
# 返回矩阵中的所有单元格的坐标，并按与 (rCenter, cCenter) 的 距离 从最小到最大的顺序排。你可以按 任何 满足此条件的顺序返回答案。
# 
# 单元格(r1, c1) 和 (r2, c2) 之间的距离为|r1 - r2| + |c1 - c2|。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：rows = 1, cols = 2, rCenter = 0, cCenter = 0
# 输出：[[0,0],[0,1]]
# 解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
# 
# 
# 示例 2：
# 
# 
# 输入：rows = 2, cols = 2, rCenter = 0, cCenter = 1
# 输出：[[0,1],[0,0],[1,1],[1,0]]
# 解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
# [[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
# 
# 
# 示例 3：
# 
# 
# 输入：rows = 2, cols = 3, rCenter = 1, cCenter = 2
# 输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
# 解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
# 其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= rows, cols <= 100
# 0 <= rCenter < rows
# 0 <= cCenter < cols
# 
# 
#

# @lc code=start
class Solution:
    # 66: 30.94%(72ms) 40.07%(17.1MB);
    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> List[List[int]]:
        # (0, 0) (0, cols-1) (rows-1, 0) (rows-1, cols-1)
        maxd = max([rCenter + cCenter, rCenter + abs(cCenter-(cols-1)), 
                    abs(rCenter-(rows-1)) + cCenter, abs(rCenter-(rows-1)) + abs(cCenter-(cols-1))])
        ret = []
        for d in range(maxd+1):
            for d1 in range(d+1):
                # rCenter + d1, cCenter + d2
                d2 = d - d1
                if d1 == 0:
                    row, col = rCenter + d1, cCenter + d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                    if d2 == 0:
                        break
                    row, col = rCenter + d1, cCenter - d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                elif d2 == 0:
                    row, col = rCenter + d1, cCenter + d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                    row, col = rCenter - d1, cCenter + d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                else:
                    row, col = rCenter + d1, cCenter + d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                    row, col = rCenter + d1, cCenter - d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                        
                    row, col = rCenter - d1, cCenter + d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
                    row, col = rCenter - d1, cCenter - d2
                    if 0 <= row and row < rows and 0 <= col and col < cols:
                        ret.append([row, col])
        return ret
# @lc code=end

'''
1\n2\n0\n0\n
2\n2\n0\n1\n
2\n3\n1\n2\n
'''