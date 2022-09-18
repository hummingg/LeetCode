#
# @lc app=leetcode.cn id=793 lang=python3
#
# [793] 阶乘函数后 K 个零
#
# https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/description/
#
# algorithms
# Hard (40.72%)
# Likes:    96
# Dislikes: 0
# Total Accepted:    9.6K
# Total Submissions: 23.5K
# Testcase Example:  '0'
#
#  f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
# 
# 
# 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
# 
# 
# 给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
# 
# 
# 
# 示例 1： 
# 
# 
# 输入：k = 0
# 输出：5
# 解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
# 
# 
# 示例 2：
# 
# 
# 输入：k = 5
# 输出：0
# 解释：没有匹配到这样的 x!，符合 k = 5 的条件。
# 
# 示例 3:
# 
# 
# 输入: k = 3
# 输出: 5
# 
# 
# 
# 
# 提示:
# 
# 
# 0 <= k <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    # 44: 58.89%(40ms) 6.3%(15.1MB);99.63%(28ms) 5.19%(15.2MB);
    def preimageSizeFZF(self, k: int) -> int:
        # self.preimageSizeFZF_TEST()
        if k == 0:
            return 5
        cnt = [0] * 15
        for i in range(1, 15):
            cnt[i] = 5 * cnt[i-1] + 1
        # for i in range(1, 15):
        #     print(5 ** i, cnt[i])
        # [0, 1, 6, 31]
        exps = [14]
        while k != 0:
            for i in range(exps[-1], 0, -1):
                if cnt[i] <= k:
                    exps.append(i)
                    k -= cnt[i]
                    break
        exps.pop(0)
        cnter = Counter(exps)
        for key in cnter.keys():
            if cnter.get(key) >= 5:
                return 0
        # ret = 0
        # for i in range(len(exps)):
        #     ret += 5 ** exps[i]
        # return ret
        return 5
    
    def preimageSizeFZF_TEST(self) -> int:
        limit = 5 * 10 ** 5 # 1249999988个0
        # print(limit)
        ret = 0
        for i in range(5, limit, 5):
            cur = 0
            # prnt = str(i)
            while i % 5 == 0:
                cur += 1
                i //= 5
            # print(prnt, cur)
            ret += cur
        return ret
    
# print(Solution().preimageSizeFZF_TEST(1))
# @lc code=end
'''
0\n
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

999999990\n
999999991\n
999999992\n
999999993\n
999999994\n
999999995\n
999999996\n
999999997\n
999999998\n
999999999\n
1000000000\n
'''
