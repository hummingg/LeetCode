#
# @lc app=leetcode.cn id=667 lang=python3
#
# [667] 优美的排列 II
#
# https://leetcode.cn/problems/beautiful-arrangement-ii/description/
#
# algorithms
# Medium (62.06%)
# Likes:    111
# Dislikes: 0
# Total Accepted:    10.4K
# Total Submissions: 16.8K
# Testcase Example:  '3\n1'
#
# 给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：
# 
# 
# 假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 -
# a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
# 
# 
# 返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 3, k = 1
# 输出：[1, 2, 3]
# 解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
# 
# 
# 示例 2：
# 
# 
# 输入：n = 3, k = 2
# 输出：[1, 3, 2]
# 解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
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
# 
#

# @lc code=start
class Solution:
    # 70: 96.23%(32ms) 96.86%(15.7MB);
    def constructArray(self, n: int, k: int) -> List[int]:
        '''
            # n个数, 会产生n-1个邻差
            # n=5,k=3: [5 1 4] 3 2 1
            # n=5,k=4: [5 1 4 2] 3
            # n=6,k=5: [6 1 5 2 4] 3]
            # n,k: n 1 n-1 2 ... [n+1-(k+1)//2] [(k+1)//2] 
            # 大数(k+1)//2个, 小数k-(k+1)//2个
            # 最后一个：
            # k偶: k-(k+1)//2, 小数
            # k奇: n-(k-1)//2, 大数
        '''
        ret = []
        big, small = n, 1
        for _ in range(k//2):
            ret.extend([big, small])
            big -= 1
            small += 1
        if k % 2 == 1:
            ret.extend(range(big, big-(n-k)-1, -1))
            # ret.append(big)
            # big -= 1
            # for i in range(n-k):
            #     ret.append(big-i)
        else:
            ret.extend(range(small, small+(n-k)))
            # for i in range(n-k):
            #     ret.append(small+i)
        return ret
        
        
# @lc code=end

