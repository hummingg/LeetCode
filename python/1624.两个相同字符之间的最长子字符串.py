#
# @lc app=leetcode.cn id=1624 lang=python3
#
# [1624] 两个相同字符之间的最长子字符串
#
# https://leetcode.cn/problems/largest-substring-between-two-equal-characters/description/
#
# algorithms
# Easy (61.89%)
# Likes:    30
# Dislikes: 0
# Total Accepted:    22.5K
# Total Submissions: 35.6K
# Testcase Example:  '"aa"'
#
# 给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。
# 
# 子字符串 是字符串中的一个连续字符序列。
# 
# 
# 
# 示例 1：
# 
# 输入：s = "aa"
# 输出：0
# 解释：最优的子字符串是两个 'a' 之间的空子字符串。
# 
# 示例 2：
# 
# 输入：s = "abca"
# 输出：2
# 解释：最优的子字符串是 "bc" 。
# 
# 
# 示例 3：
# 
# 输入：s = "cbzxy"
# 输出：-1
# 解释：s 中不存在出现出现两次的字符，所以返回 -1 。
# 
# 
# 示例 4：
# 
# 输入：s = "cabbac"
# 输出：4
# 解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 300
# s 只含小写英文字母
# 
# 
#

# @lc code=start
class Solution:
    # 54: 58.51%(40ms) 7.09%(15.1MB); 81.91%(36ms) 34.75%(15MB); 93.97%(32ms) 55.32%(14.9MB);
    # 99.29%(28ms) 10.28%(15.1MB);
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = [i]
            elif len(d[s[i]]) == 1:
                d[s[i]].append(i)
            else:
                d[s[i]][1] = i
        ret = -1
        for _, v in d.items():
            if len(v) == 1:
                continue
            ret = max(ret, v[-1]-v[0]-1)
        return ret
    
    # 54: 93.97%(32ms) 52.13%(14.9MB);
    def maxLengthBetweenEqualCharacters1(self, s: str) -> int:
        ret = -1
        for i in range(len(s)):
            for j in range(len(s)-1, i, -1):
                if s[i] == s[j]:
                    ret = max(ret, j-i-1)
                    break
        return ret
        
# @lc code=end
'''
"aa"\n
"abca"\n
"cbzxy"\n
"cabbac"\n
"mgntdygtxrvxjnwksqhxuxtrv"\n
'''
