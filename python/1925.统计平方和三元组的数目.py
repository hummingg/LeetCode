#
# @lc app=leetcode.cn id=1925 lang=python3
#
# [1925] 统计平方和三元组的数目
#
# https://leetcode.cn/problems/count-square-sum-triples/description/
#
# algorithms
# Easy (69.86%)
# Likes:    12
# Dislikes: 0
# Total Accepted:    8.8K
# Total Submissions: 12.6K
# Testcase Example:  '5'
#
# 一个 平方和三元组 (a,b,c) 指的是满足 a^2 + b^2 = c^2 的 整数 三元组 a，b 和 c 。
# 
# 给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。
# 
# 
# 
# 示例 1：
# 
# 输入：n = 5
# 输出：2
# 解释：平方和三元组为 (3,4,5) 和 (4,3,5) 。
# 
# 
# 示例 2：
# 
# 输入：n = 10
# 输出：4
# 解释：平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 250
# 
# 
#

# @lc code=start
from math import ceil, sqrt


class Solution:
    # 91: 74%(344ms) 69.6%(14.8MB);
    def countTriples(self, n: int) -> int:
        ret = 0
        for a in range(1, n+1):
            a2 = a ** 2
            for b in range(a, n+1):
                sq = sqrt(a2 + b ** 2)
                nt = int(sq)
                if nt <= n and ceil(sq) == nt:
                    if a == b:
                        ret += 1
                    else:
                        ret += 2
        return ret
# @lc code=end

