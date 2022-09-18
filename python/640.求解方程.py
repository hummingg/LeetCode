#
# @lc app=leetcode.cn id=640 lang=python3
#
# [640] 求解方程
#
# https://leetcode.cn/problems/solve-the-equation/description/
#
# algorithms
# Medium (42.45%)
# Likes:    91
# Dislikes: 0
# Total Accepted:    13.2K
# Total Submissions: 31K
# Testcase Example:  '"x+5-3+x=6+x-2"'
#
# 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
# 
# 如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
# 
# 如果方程中只有一个解，要保证返回值 'x' 是一个整数。
# 
# 
# 
# 示例 1：
# 
# 
# 输入: equation = "x+5-3+x=6+x-2"
# 输出: "x=2"
# 
# 
# 示例 2:
# 
# 
# 输入: equation = "x=x"
# 输出: "Infinite solutions"
# 
# 
# 示例 3:
# 
# 
# 输入: equation = "2x=x"
# 输出: "x=0"
# 
# 
# 
# 
# 
# 
# 提示:
# 
# 
# 3 <= equation.length <= 1000
# equation 只有一个 '='.
# equation 方程由整数组成，其绝对值在 [0, 100] 范围内，不含前导零和变量 'x' 。 ​​​
# 
# 
#

# @lc code=start
class Solution:
    # 59: 16.25%(44ms) 96.88%(14.9MB);
    # 如果方程中只有一个解，要保证返回值 'x' 是一个整数？？题目保证？
    def solveEquation(self, equation: str) -> str:
        left, leftx, right, rightx = 0, 0, 0, 0
        # 左边
        buffer = ''
        for i in range(len(equation)):
            if equation[i] == '=':
                break
            if equation[i] in ['+', '-']:
                
                if 'x' in buffer:
                    # x 2x +x -x +2x -2x
                    if len(buffer) == 1 or len(buffer) == 2 and buffer[0] in ['+','-']:
                        buffer = buffer[:-1] + '1'
                    else:
                        buffer = buffer[:-1]
                    leftx += int(buffer)
                elif buffer != '':
                    left += int(buffer)
                buffer = equation[i]
            else:
                buffer += equation[i]
        if 'x' in buffer:
            if len(buffer) == 1 or len(buffer) == 2 and buffer[0] in ['+','-']:
                buffer = buffer[:-1] + '1'
            else:
                buffer = buffer[:-1]
            leftx += int(buffer)
        elif buffer != '':
            left += int(buffer)
        
        # 右边
        buffer = ''
        i += 1
        while i < len(equation):
            if equation[i] in ['+', '-']:
                if 'x' in buffer:
                    if len(buffer) == 1 or len(buffer) == 2 and buffer[0] in ['+','-']:
                        buffer = buffer[:-1] + '1'
                    else:
                        buffer = buffer[:-1]
                    rightx += int(buffer)
                elif buffer != '':
                    right += int(buffer)
                buffer = equation[i]
            else:
                buffer += equation[i]
            i += 1
        if 'x' in buffer:
            if len(buffer) == 1 or len(buffer) == 2 and buffer[0] in ['+','-']:
                buffer = buffer[:-1] + '1'
            else:
                buffer = buffer[:-1]
            rightx += int(buffer)
        elif buffer != '':
            right += int(buffer)
        # print(leftx, rightx, left, right)
        x = leftx - rightx
        b = left - right
        if x == 0:
            return 'No solution' if b != 0 else 'Infinite solutions'
        return 'x=' + str(-b // x) if abs(b) % abs(x) == 0 else 'No solution'
        
        
# @lc code=end
'''
"x+5-3+x=6+x-2"\n
"x=x"\n
"2x=x"\n
"2=1"\n
"2x+3x-6x=x+2"\n
"-x=-1"\n

"3x=x+1"\n
'''
