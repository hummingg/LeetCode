#
# @lc app=leetcode.cn id=696 lang=python3
#
# [696] 计数二进制子串
#
# https://leetcode.cn/problems/count-binary-substrings/description/
#
# algorithms
# Easy (63.84%)
# Likes:    471
# Dislikes: 0
# Total Accepted:    63.4K
# Total Submissions: 99.3K
# Testcase Example:  '"00110011"'
#
# 给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。
# 
# 重复出现（不同位置）的子串也要统计它们出现的次数。
# 
# 
# 示例 1：
# 
# 
# 输入：s = "00110011"
# 输出：6
# 解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
# 注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
# 另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
# 
# 示例 2：
# 
# 
# 输入：s = "10101"
# 输出：4
# 解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 10^5
# s[i] 为 '0' 或 '1'
# 
# 
#

# @lc code=start
class Solution:
    # 91: 15.16%(232ms) 85.95%(15.2MB);
    # TLE: 86/91
    def countBinarySubstrings(self, s: str) -> int:
        size = len(s)
        ret = 0
        i = 0
        while i < size:
            j = i
            while j < size and s[j] == s[i]:
                j += 1
            k = j
            flag = False
            while k < size and s[k] == s[j]:
                k += 1
            #     if j-i == k-j:
            #         ret += j-i
            #         flag = True
            #         break
            # i = j if flag else i+1  # !
            r = min(j-i, k-j)
            ret += r
            i = j   # ToOpt
        return ret
            
# @lc code=end
'''
"00110011"\n
"10101"\n
"00110"\n
'''
