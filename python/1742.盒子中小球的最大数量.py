#
# @lc app=leetcode.cn id=1742 lang=python3
#
# [1742] 盒子中小球的最大数量
#
# https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/description/
#
# algorithms
# Easy (71.03%)
# Likes:    19
# Dislikes: 0
# Total Accepted:    10.9K
# Total Submissions: 15.4K
# Testcase Example:  '1\n10'
#
# 你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit
# ，即 n == highLimit - lowLimit + 1）。另有无限数量的盒子，编号从 1 到 infinity 。
# 
# 你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6
# 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。
# 
# 给你两个整数 lowLimit 和 highLimit
# ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：lowLimit = 1, highLimit = 10
# 输出：2
# 解释：
# 盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
# 小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
# 编号 1 的盒子放有最多小球，小球数量为 2 。
# 
# 示例 2：
# 
# 
# 输入：lowLimit = 5, highLimit = 15
# 输出：2
# 解释：
# 盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
# 小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
# 编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
# 
# 
# 示例 3：
# 
# 
# 输入：lowLimit = 19, highLimit = 28
# 输出：2
# 解释：
# 盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
# 小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
# 编号 10 的盒子放有最多小球，小球数量为 2 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 
# 
# 
#

# @lc code=start
class Solution:
    # 97: 67.84%(320ms) 97.66%(14.8MB);
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        d = {}
        for i in range(lowLimit, highLimit + 1):
            sum = self.sumDigits(i)
            if sum in d:
                d[sum] += 1
            else:
                d[sum] = 1
        # print(d)
        return max(d.values())
        
    def sumDigits(self, num: int) -> int:
        ret = 0
        while num > 0:
            ret += num % 10
            num //= 10
        return ret
    
    # 数学不会
    def countBalls9(self, lowLimit: int, highLimit: int) -> int:
        ten = (lowLimit // 10 + 1) * 10
        hun = (lowLimit // 100 + 1) * 100
        # low -> %10 -> n * 100
        
        # n * 100 -> % 10 -> high
        return 0
# @lc code=end

'''
1\n10\n
5\n15\n
19\n28

000-009: 0 ->  9
010-019: 1 -> 10
020-029: 2 -> 11
...
090-099: 9 -> 18=9*2

1:  1 1 1 ...  1  0  0 ...  0  0
    0 1 2 ...  9 10 11 ... 17 18
2:  1 2 3 ... 10  9  8 ...  2  1    10+45*2=100

100-199:
    100-109:  1 -> 10
    110-119:  2 -> 11
    120-129:  3 -> 12
    ...
    190-199: 10 -> 19
    
200-299:
    200-209:  2 -> 11
    210-219:  3 -> 12
    220-229:  4 -> 13
    ...
    290-299: 11 -> 20
    
    
'''