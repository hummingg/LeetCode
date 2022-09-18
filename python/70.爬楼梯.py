#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#
# https://leetcode.cn/problems/climbing-stairs/description/
#
# algorithms
# Easy (53.96%)
# Likes:    2617
# Dislikes: 0
# Total Accepted:    943.7K
# Total Submissions: 1.7M
# Testcase Example:  '2'
#
# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
# 
# 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 2
# 输出：2
# 解释：有两种方法可以爬到楼顶。
# 1. 1 阶 + 1 阶
# 2. 2 阶
# 
# 示例 2：
# 
# 
# 输入：n = 3
# 输出：3
# 解释：有三种方法可以爬到楼顶。
# 1. 1 阶 + 1 阶 + 1 阶
# 2. 1 阶 + 2 阶
# 3. 2 阶 + 1 阶
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 45
# 
# 
#

# @lc code=start
class Solution:
    # 45: 87.39%(32ms) 95.35%(14.8MB);
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            # print(str(i)+'\\n')
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
# @lc code=end
Solution().climbStairs(n=45)

'''
2\n
3\n
4\n
5\n
6\n
7\n
8\n
9\n
10\n
11\n
12\n
13\n
14\n
15\n
16\n
17\n
18\n
19\n
20\n
21\n
22\n
23\n
24\n
25\n
26\n
27\n
28\n
29\n
30\n
31\n
32\n
33\n
34\n
35\n
36\n
37\n
38\n
39\n
40\n
41\n
42\n
43\n
44\n
45\n
'''
