#
# @lc app=leetcode.cn id=766 lang=python3
#
# [766] 托普利茨矩阵
#
# https://leetcode.cn/problems/toeplitz-matrix/description/
#
# algorithms
# Easy (70.55%)
# Likes:    273
# Dislikes: 0
# Total Accepted:    62.1K
# Total Submissions: 88.1K
# Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
#
# 给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。
# 
# 如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
# 输出：true
# 解释：
# 在上述矩阵中, 其对角线为: 
# "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。 
# 各条对角线上的所有元素均相同, 因此答案是 True 。
# 
# 
# 示例 2：
# 
# 
# 输入：matrix = [[1,2],[2,2]]
# 输出：false
# 解释：
# 对角线 "[1, 2]" 上的元素不同。
# 
# 
# 
# 提示：
# 
# 
# m == matrix.length
# n == matrix[i].length
# 1 
# 0 
# 
# 
# 
# 
# 进阶：
# 
# 
# 如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
# 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
# 
# 
#

# @lc code=start
class Solution:
    # 483: 43.64%(44ms) 75.81%(15MB);
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        # 超进阶：一次只能将 1 个元素加载到内存中
        # N = 1
        m, n = len(matrix), len(matrix[0])
        total, cnt = m * n, 0
        row = []
        while cnt < n:
            row.append(matrix[cnt // n][cnt - cnt // n * m])    # 读1个元素
            cnt += 1    # 待读入内存的元素的一维索引，从0开始计
        # print(row)
        while cnt < total:
            for i in range(0, n-1):
                # print(matrix[(cnt+i+1) // n][(cnt+i+1) % n])
                if row[i] != matrix[(cnt+i+1) // n][(cnt+i+1) % n]:  # 读1个元素
                    return False
            row.pop()
            row.insert(0, matrix[cnt // n][cnt % n]) # 读1个元素，第 k*n 个元素
            cnt += n
        return True
# @lc code=end

