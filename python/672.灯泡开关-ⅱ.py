#
# @lc app=leetcode.cn id=672 lang=python3
#
# [672] 灯泡开关 Ⅱ
#
# https://leetcode.cn/problems/bulb-switcher-ii/description/
#
# algorithms
# Medium (54.00%)
# Likes:    122
# Dislikes: 0
# Total Accepted:    8.2K
# Total Submissions: 14.1K
# Testcase Example:  '1\n1'
#
# 房间中有 n 只已经打开的灯泡，编号从 1 到 n 。墙上挂着 4 个开关 。
# 
# 这 4 个开关各自都具有不同的功能，其中：
# 
# 
# 开关 1 ：反转当前所有灯的状态（即开变为关，关变为开）
# 开关 2 ：反转编号为偶数的灯的状态（即 2, 4, ...）
# 开关 3 ：反转编号为奇数的灯的状态（即 1, 3, ...）
# 开关 4 ：反转编号为 j = 3k + 1 的灯的状态，其中 k = 0, 1, 2, ...（即 1, 4, 7, 10, ...）
# 
# 
# 你必须 恰好 按压开关 presses 次。每次按压，你都需要从 4 个开关中选出一个来执行按压操作。
# 
# 给你两个整数 n 和 presses ，执行完所有按压之后，返回 不同可能状态 的数量。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 1, presses = 1
# 输出：2
# 解释：状态可以是：
# - 按压开关 1 ，[关]
# - 按压开关 2 ，[开]
# 
# 
# 示例 2：
# 
# 
# 输入：n = 2, presses = 1
# 输出：3
# 解释：状态可以是：
# - 按压开关 1 ，[关, 关]
# - 按压开关 2 ，[开, 关]
# - 按压开关 3 ，[关, 开]
# 
# 
# 示例 3：
# 
# 
# 输入：n = 3, presses = 1
# 输出：4
# 解释：状态可以是：
# - 按压开关 1 ，[关, 关, 关]
# - 按压开关 2 ，[关, 开, 关]
# - 按压开关 3 ，[开, 关, 开]
# - 按压开关 4 ，[关, 开, 开]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 1000
# 0 <= presses <= 1000
# 
# 
#

# @lc code=start
class Solution:
    # 80: 90.37%(32ms) 28.15%(15.1MB);
    def flipLights(self, n: int, presses: int) -> int:
        # 1 2 3 4 5 6 [7 8 9 10 11 12] ...
        
        # 按压顺序不同但次数相同，结果相同吗？相同，所以找四个开关奇数、偶数的组合，正则表达为[奇|偶]{4,}，最多2^4=16中组合。
        # ①presses为偶数时，(按压次数为奇数的开关数，按压次数为偶数的开关数)：(0,4)[C(4,0)=1] (2,2)[C(4,2)=6] (4,0)[C(4,4)=1]
        # presses=4已包含所有8种按压情况，presses=6+可随便浪费偶数次按压回到presses=4的情况
        # (0,4)：(4, 0, 0, 0) 
        # (2,2)：(1, 1, 2, 0) (1, 2, 1, 0) (1, 2, 0, 1) (2, 1, 1, 0) (2, 1, 0, 1) (2, 0, 1, 1)
        # (4,0)：(1, 1, 1, 1)
        # ②presses为奇数时，(按压次数为奇数的开关数，按压次数为偶数的开关数)：(1,3)[C(4,1)=4] (3,1)[C(4,3)=4]
        # presses=3已包含所有8种按压情况，presses=5+可随便浪费偶数次按压回到presses=3的情况
        # (1,3)：(3, 0, 0, 0) (0, 3, 0, 0) (0, 0, 3, 0) (0, 0, 0, 3)
        # (3,1)：(0, 1, 1, 1) (1, 0, 1, 1) (1, 1, 0, 1) (1, 1, 1, 0)
        
        # 降低时空复杂度
        n = min(n, 6)
        if presses % 2 == 0:
            presses = min(presses, 4)
        else:
            presses = min(presses, 3)
        if n == 6 and presses in [3,4]:
            return 8

        statuso = [True] * (n+1) # 初始状态：已经打开。索引0为哨兵。
        st = set()
        for I in range(presses+1):
            for J in range(presses+1-I):
                for K in range(presses+1-I-J):
                    L = presses - I - J - K
                    status = statuso
                    if I % 2 == 1:
                        status = [True] + [not status[i] for i in range(1, n+1)]
                    if J % 2 == 1:
                        status = [True] + [not status[i] if i%2==0 else status[i] for i in range(1, n+1)]
                    if K % 2 == 1:
                        status = [True] + [not status[i] if i%2==1 else status[i] for i in range(1, n+1)]
                    if L % 2 == 1:
                        status = [True] + [not status[i] if i%3==1 else status[i] for i in range(1, n+1)]
                    st.add(tuple(status))
        return len(st)
        
# @lc code=end
'''
1\n1\n
2\n1\n
3\n1\n
1000\n4\n
1000\n100\n
1000\n1000\n
1\n1000\n

开始: [1,1,1]
[0,0,0]
[1,0,1]
[0,1,0]
[0,1,1]

'''
