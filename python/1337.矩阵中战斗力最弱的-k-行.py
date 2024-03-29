#
# @lc app=leetcode.cn id=1337 lang=python3
#
# [1337] 矩阵中战斗力最弱的 K 行
#
# https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix/description/
#
# algorithms
# Easy (68.95%)
# Likes:    181
# Dislikes: 0
# Total Accepted:    50.8K
# Total Submissions: 73.6K
# Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
#
# 给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。
# 
# 请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。
# 
# 如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。
# 
# 军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：mat = 
# [[1,1,0,0,0],
# ⁠[1,1,1,1,0],
# ⁠[1,0,0,0,0],
# ⁠[1,1,0,0,0],
# ⁠[1,1,1,1,1]], 
# k = 3
# 输出：[2,0,3]
# 解释：
# 每行中的军人数目：
# 行 0 -> 2 
# 行 1 -> 4 
# 行 2 -> 1 
# 行 3 -> 2 
# 行 4 -> 5 
# 从最弱到最强对这些行排序后得到 [2,0,3,1,4]
# 
# 
# 示例 2：
# 
# 
# 输入：mat = 
# [[1,0,0,0],
# [1,1,1,1],
# [1,0,0,0],
# [1,0,0,0]], 
# k = 2
# 输出：[0,2]
# 解释： 
# 每行中的军人数目：
# 行 0 -> 1 
# 行 1 -> 4 
# 行 2 -> 1 
# 行 3 -> 1 
# 从最弱到最强对这些行排序后得到 [0,2,3,1]
# 
# 
# 
# 
# 提示：
# 
# 
# m == mat.length
# n == mat[i].length
# 2 
# 1 
# matrix[i][j] 不是 0 就是 1
# 
# 
#

# @lc code=start
class Solution:
    # 52: 98.58%(28ms) 83.66%(15.1MB);
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        acks = [[sum(mat[i]), i] for i in range(len(mat))]
        acks.sort()
        return [ ack[1] for ack in acks[:k]]
# @lc code=end

