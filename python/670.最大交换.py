#
# @lc app=leetcode.cn id=670 lang=python3
#
# [670] 最大交换
#
# https://leetcode.cn/problems/maximum-swap/description/
#
# algorithms
# Medium (46.37%)
# Likes:    285
# Dislikes: 0
# Total Accepted:    34.2K
# Total Submissions: 72.7K
# Testcase Example:  '2736'
#
# 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
# 
# 示例 1 :
# 
# 
# 输入: 2736
# 输出: 7236
# 解释: 交换数字2和数字7。
# 
# 
# 示例 2 :
# 
# 
# 输入: 9973
# 输出: 9973
# 解释: 不需要交换。
# 
# 
# 注意:
# 
# 
# 给定数字的范围是 [0, 10^8]
# 
# 
#

# @lc code=start
class Solution:
    # 111: 68.71%(36ms) 33.47%(15MB);
    def maximumSwap(self, num: int) -> int:
        ns = list(map(lambda x: int(x), list(str(num))))
        
        # [2] [7] 3 6
        nso = ns[:] # 切片复制法
        # [7] 6 3 2
        ns.sort(reverse=True)
        
        size = len(ns)
        dif = 0
        while dif < size and ns[dif] == nso[dif]:
            dif += 1
        if dif == size:
            return num
        target = ns[dif]
        for i in range(size-1, dif, -1):
            if target == nso[i]:
                target = i  # 要交换的索引
                break
        nso[dif], nso[target] = nso[target], nso[dif]
        return reduce(lambda x, y: x*10 + y, nso)
# @lc code=end

