#
# @lc app=leetcode.cn id=292 lang=python3
#
# [292] Nim 游戏
#
# https://leetcode.cn/problems/nim-game/description/
#
# algorithms
# Easy (70.66%)
# Likes:    604
# Dislikes: 0
# Total Accepted:    139.1K
# Total Submissions: 196.8K
# Testcase Example:  '4'
#
# 你和你的朋友，两个人一起玩 Nim 游戏：
# 
# 
# 桌子上有一堆石头。
# 你们轮流进行自己的回合， 你作为先手 。
# 每一回合，轮到的人拿掉 1 - 3 块石头。
# 拿掉最后一块石头的人就是获胜者。
# 
# 
# 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false
# 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 4
# 输出：false 
# 解释：以下是可能的结果:
# 1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
# 2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
# 3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
# 在所有结果中，你的朋友是赢家。
# 
# 
# 示例 2：
# 
# 
# 输入：n = 1
# 输出：true
# 
# 
# 示例 3：
# 
# 
# 输入：n = 2
# 输出：true
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 2^31 - 1
# 
# 
#

# @lc code=start
class Solution:
    # 60: 86.86%(32ms) 88%(14.8MB);
    def canWinNim(self, n: int) -> bool:
        # (TTTF)*
        return n % 4 != 0
        
        # print((1 << 31) - 1)
        dp = [True] * max([(n+1), 4])   # MemoryError
        # dp[1] = True
        # dp[2] = True
        # dp[3] = True
        for i in range(4, n+1):
            # for j in [1,2,3]:
            if dp[i-1] and dp[i-2] and dp[i-3]:
                dp[i] = False
        return dp[n]
    
# print(1)
# s = Solution()
# for i in range(1, 50):
#     print(s.canWinNim(i))

# if __name__ == '__main__':
#     s = Solution()
#     for i in range(1, 50):
#         print(s.canWinNim(i))
# @lc code=end
'''\
1\n
2\n
3\n
4\n
2147483647\n
'''
