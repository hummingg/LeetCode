#
# @lc app=leetcode.cn id=171 lang=python3
#
# [171] Excel 表列序号
#
# https://leetcode.cn/problems/excel-sheet-column-number/description/
#
# algorithms
# Easy (71.64%)
# Likes:    336
# Dislikes: 0
# Total Accepted:    135.5K
# Total Submissions: 189.2K
# Testcase Example:  '"A"'
#
# 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
# 
# 例如：
# 
# 
# A -> 1
# B -> 2
# C -> 3
# ...
# Z -> 26
# AA -> 27
# AB -> 28 
# ...
# 
# 
# 
# 示例 1:
# 
# 
# 输入: columnTitle = "A"
# 输出: 1
# 
# 
# 示例 2:
# 
# 
# 输入: columnTitle = "AB"
# 输出: 28
# 
# 
# 示例 3:
# 
# 
# 输入: columnTitle = "ZY"
# 输出: 701
# 
# 
# 
# 提示：
# 
# 
# 1 <= columnTitle.length <= 7
# columnTitle 仅由大写英文组成
# columnTitle 在范围 ["A", "FXSHRXW"] 内
# 
# 
#



# @lc code=start
class Solution:
    # 1002: 25.59%(44ms) 69.84%(14.9MB);56.81%(40ms) 83.03%(14.9MB);80.5%(36ms) 5.1%(15.1MB);
    def titleToNumber(self, columnTitle: str) -> int:
        ret = 0
        for c in columnTitle:
            ret = ret * 26 + ord(c) - ord('A') + 1
        return ret
# @lc code=end
'''
'
"A"\n
"AB"\n
"ZY"
'
'''
