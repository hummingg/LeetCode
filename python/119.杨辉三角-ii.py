#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#
# https://leetcode.cn/problems/pascals-triangle-ii/description/
#
# algorithms
# Easy (68.66%)
# Likes:    415
# Dislikes: 0
# Total Accepted:    219K
# Total Submissions: 318.9K
# Testcase Example:  '3'
#
# 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
# 
# 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
# 
# 
# 
# 
# 
# 示例 1:
# 
# 
# 输入: rowIndex = 3
# 输出: [1,3,3,1]
# 
# 
# 示例 2:
# 
# 
# 输入: rowIndex = 0
# 输出: [1]
# 
# 
# 示例 3:
# 
# 
# 输入: rowIndex = 1
# 输出: [1,1]
# 
# 
# 
# 
# 提示:
# 
# 
# 0 
# 
# 
# 
# 
# 进阶：
# 
# 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
# 
#

# @lc code=start
class Solution:
    # 34: 72.44%(36ms) 29.46%(14.9MB);
    # 进阶 O(rowIndex)
    def getRow0(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        return [self.C(rowIndex, i) for i in range(rowIndex+1)]
    
    # 34: 43.98%(40ms) 42.85%(14.9MB);
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]
        while rowIndex > 0:
            newrow = [1]
            for i in range(len(row)-1):
                newrow.append(row[i] + row[i+1])
            row = newrow
            row.append(1)
            rowIndex -= 1
        return row
    
    def C(self, m: int, n: int) -> int:
        if n == 0:
            return 1
        numer, deno = 1, 1
        for i in range(1, n+1):
            deno *= i
            numer *= m-i+1
        return numer // deno
            
            
# @lc code=end

