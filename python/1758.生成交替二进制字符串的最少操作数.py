#
# @lc app=leetcode.cn id=1758 lang=python3
#
# [1758] 生成交替二进制字符串的最少操作数
#
# https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/description/
#
# algorithms
# Easy (63.65%)
# Likes:    38
# Dislikes: 0
# Total Accepted:    10K
# Total Submissions: 15.8K
# Testcase Example:  '"0100"'
#
# 给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。
# 
# 交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100"
# 不是。
# 
# 返回使 s 变成 交替字符串 所需的 最少 操作数。
# 
# 
# 
# 示例 1：
# 
# 输入：s = "0100"
# 输出：1
# 解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
# 
# 
# 示例 2：
# 
# 输入：s = "10"
# 输出：0
# 解释：s 已经是交替字符串。
# 
# 
# 示例 3：
# 
# 输入：s = "1111"
# 输出：2
# 解释：需要 2 步操作得到 "0101" 或 "1010" 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 10^4
# s[i] 是 '0' 或 '1'
# 
# 
#

# @lc code=start
class Solution:
    def minOperations(self, s: str) -> int:
        # 第一个字符串是0还是1决定整个字符串对应的交替字符串
        n = len(s)
        dp = [[0, 0] for _ in range(n)]
        dp[0][0] = 0 if s[0] == '0' else 1  # 0开头，偶数是0奇数是1
        dp[0][1] = 0 if s[0] == '1' else 1  # 1开头，偶数是1奇数是0
        for i in range(1, n):
            if i % 2 == 0:
                # if s[i] == '0':
                #     dp[i][0] = dp[i-1][0]
                #     dp[i][1] = dp[i-1][1] + 1
                # else:
                #     dp[i][0] = dp[i-1][0] + 1
                #     dp[i][1] = dp[i-1][1]
                dp[i][0] = dp[i-1][0] + 1 if s[i] == '1' else 0
                dp[i][1] = dp[i-1][1] + 1 if s[i] == '0' else 0
            else:
                # if s[i] == '0':
                #     dp[i][0] = dp[i-1][0] + 1
                #     dp[i][1] = dp[i-1][1]
                # else:
                #     dp[i][0] = dp[i-1][0]
                #     dp[i][1] = dp[i-1][1] + 1
                dp[i][0] = dp[i-1][0] + 1 if s[i] == '0' else 0
                dp[i][1] = dp[i-1][1] + 1 if s[i] == '1' else 0
        return min(dp[n-1][0], dp[n-1][1])
# @lc code=end
'''
"0100"\n
"10"\n
"1111"\n
'''
