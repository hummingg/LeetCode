#
# @lc app=leetcode.cn id=1025 lang=python3
#
# [1025] 除数博弈
#
# https://leetcode.cn/problems/divisor-game/description/
#
# algorithms
# Easy (70.75%)
# Likes:    363
# Dislikes: 0
# Total Accepted:    87.4K
# Total Submissions: 123.6K
# Testcase Example:  '2'
#
# 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
# 
# 最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：
# 
# 
# 选出任一 x，满足 0 < x < n 且 n % x == 0 。
# 用 n - x 替换黑板上的数字 n 。
# 
# 
# 如果玩家无法执行这些操作，就会输掉游戏。
# 
# 只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。
# 
# 
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 2
# 输出：true
# 解释：爱丽丝选择 1，鲍勃无法进行操作。
# 
# 
# 示例 2：
# 
# 
# 输入：n = 3
# 输出：false
# 解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
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
    # 40: 19.64%(64ms) 7.74%(15MB); 73.51%(36ms) 70.09%(14.8MB);
    def divisorGame(self, n: int) -> bool:
        return n % 2 == 0
    
        # n = x * k -> n = x * (k-1) -> ... -> n=1 才结束
        dp = [False] * (n+1)
        dp[1] = False
        # dp[2] = True
        for i in range(2, n+1):
            for j in range(1, i):
                if i % j == 0 and not dp[i-j]:
                    dp[i] = True
                    break
        return dp[n]
    
        # 1: F
        # 2: 1 -> [1] T
        # 3: 1 2 -> [2] 1 F
        # 4: 1 2 -> [3] 2 T
        # 5: 1 -> 4 F
        # 6: 1 2 3 -> [5] 4 [3] T
        # 7: 1 -> 6 F
        # 8: 1 2 4 -> [7] 6 4 T
        # 9: 1 3 -> 8 6 F
        # 10: 1 2 5 -> [9] 8 [5] T
        # (FT)*
# @lc code=end
'''
1\n
2\n
3\n
4\n
5\n
6\n
7\n
8\n
9\n
10\n
12\n
1000\n
'''
