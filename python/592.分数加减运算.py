#
# @lc app=leetcode.cn id=592 lang=python3
#
# [592] 分数加减运算
#
# https://leetcode.cn/problems/fraction-addition-and-subtraction/description/
#
# algorithms
# Medium (52.83%)
# Likes:    73
# Dislikes: 0
# Total Accepted:    7.5K
# Total Submissions: 13.6K
# Testcase Example:  '"-1/2+1/2"'
#
# 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
# 
# 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为
# 2/1。
# 
# 
# 
# 示例 1:
# 
# 
# 输入: expression = "-1/2+1/2"
# 输出: "0/1"
# 
# 
# 示例 2:
# 
# 
# 输入: expression = "-1/2+1/2+1/3"
# 输出: "1/3"
# 
# 
# 示例 3:
# 
# 
# 输入: expression = "1/3-1/2"
# 输出: "-1/6"
# 
# 
# 
# 
# 提示:
# 
# 
# 输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
# 输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
# 输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
# 输入的分数个数范围是 [1,10]。
# 最终结果的分子与分母保证是 32 位整数范围内的有效整数。
# 
# 
#

# @lc code=start
class Solution:
    # 105: 76.3%(36ms) 45.09%(15MB);
    def fractionAddition(self, expression: str) -> str:
        # COMMULTI = 3628800  # 10!
        size = len(expression)
        # signs = []
        numerators = [] # 所有分子，带符号
        denominators = []   # 所有分母
        i, j = 0, 0
        if expression[0] == '+' or expression[0] == '-':
            numerators.append(expression[0])
            i += 1
        else:
            numerators.append('')
        while i < size:
            while expression[i] != '/':
                numerators[j] += expression[i]
                i += 1
            i += 1
            denominators.append('')
            while i < size and expression[i] != '+' and expression[i] != '-':
                denominators[j] += expression[i]
                i += 1
            j += 1
            numerators.append('')
        numerators.pop()
        denominators = list(map(lambda x: int(x), denominators))    # 字符串转数字
        # 统一通分
        DENOMULTI = reduce(lambda x, y: x * y, denominators) # 所有分母的乘积
        numerators = [DENOMULTI // int(denominators[i]) * int(numerators[i]) for i in range(len(numerators))]
        numer = sum(numerators)
        pos = numer >= 0
        numer = abs(numer)
        retn = numer // DENOMULTI
        retnumer = numer % DENOMULTI
        if retnumer == 0:
            ret = str(retn) + '/1'
            return ret  if pos else '-' + ret
        retdenom = DENOMULTI
        # 统一约分，待除质数为 2,3,5,7
        # print(denominators, retdenom, retnumer)
        for prime in [2,3,5,7]:
            while retnumer % prime == 0 and retdenom % prime == 0:
                retnumer //= prime
                retdenom //= prime
        ret = str(retnumer + retn * retdenom) + '/' + str(retdenom)
        return ret if pos else '-' + ret
# @lc code=end
'''
'
"-1/2+1/2"\n
"-1/2+1/2+1/3"\n
"1/3-1/2"\n
"7/3+5/2-3/10"\n
'
'''
