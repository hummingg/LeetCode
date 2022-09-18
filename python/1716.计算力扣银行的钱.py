#
# @lc app=leetcode.cn id=1716 lang=python3
#
# [1716] 计算力扣银行的钱
#
# https://leetcode.cn/problems/calculate-money-in-leetcode-bank/description/
#
# algorithms
# Easy (69.82%)
# Likes:    72
# Dislikes: 0
# Total Accepted:    39K
# Total Submissions: 55.9K
# Testcase Example:  '4'
#
# Hercy 想要为购买第一辆车存钱。他 每天 都往力扣银行里存钱。
# 
# 最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。在接下来每一个周一，他都会比 前一个周一 多存入 1 块钱。 
# 
# 给你 n ，请你返回在第 n 天结束的时候他在力扣银行总共存了多少块钱。
# 
# 
# 
# 示例 1：
# 
# 输入：n = 4
# 输出：10
# 解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
# 
# 
# 示例 2：
# 
# 输入：n = 10
# 输出：37
# 解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37
# 。注意到第二个星期一，Hercy 存入 2 块钱。
# 
# 
# 示例 3：
# 
# 输入：n = 20
# 输出：96
# 解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3
# + 4 + 5 + 6 + 7 + 8) = 96 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 1000
# 
# 
#

# @lc code=start
class Solution:
    # 106: 97.9%(28ms) 77.97%(14.8MB);
    def totalMoney(self, n: int) -> int:
        # 满 n//7 周。第i周的周一存i块，第i周共存(i+i+6)*7//2块。
        weeks = n // 7
        days = n % 7
        sum = 0
        for i in range(1, weeks+1):
            sum += 7 * (i+3)
        for i in range(1, days+1):
            sum += weeks + i
        return sum
# @lc code=end

