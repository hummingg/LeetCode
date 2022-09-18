#
# @lc app=leetcode.cn id=1417 lang=python3
#
# [1417] 重新格式化字符串
#
# https://leetcode.cn/problems/reformat-the-string/description/
#
# algorithms
# Easy (51.97%)
# Likes:    29
# Dislikes: 0
# Total Accepted:    15.9K
# Total Submissions: 30.6K
# Testcase Example:  '"a0b1c2"'
#
# 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。
# 
# 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。
# 
# 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。
# 
# 
# 
# 示例 1：
# 
# 输入：s = "a0b1c2"
# 输出："0a1b2c"
# 解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
# 
# 
# 示例 2：
# 
# 输入：s = "leetcode"
# 输出：""
# 解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
# 
# 
# 示例 3：
# 
# 输入：s = "1229857369"
# 输出：""
# 解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
# 
# 
# 示例 4：
# 
# 输入：s = "covid2019"
# 输出："c2o0v1i9d"
# 
# 
# 示例 5：
# 
# 输入：s = "ab123"
# 输出："1a2b3"
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 500
# s 仅由小写英文字母和/或数字组成。
# 
# 
#

# @lc code=start
class Solution:
    # 302: 90.87%(40ms) 62.1%(15MB);
    def reformat(self, s: str) -> str:
        chs, nums = [], []
        for ch in s:
            if 'a' <= ch and ch <= 'z':
                chs.append(ch)
            if '0' <= ch and ch <= '9':
                nums.append(ch)
        chl, numl = len(chs), len(nums)
        if abs(chl - numl) > 1:
            return ''
        ret = ''
        if chl == numl:
            for i in range(chl):
                ret += chs[i]
                ret += nums[i]
            return ret
        long, short = '', ''
        if chl > numl:
            long = chs
            short = nums
        else:
            long = nums
            short = chs
        for i in range(len(long)-1):
            ret += long[i]
            ret += short[i]
        ret += long[-1]
        return ret
# @lc code=end
'''
"a0b1c2"\n
"leetcode"\n
"1229857369"\n
"covid2019"\n
"ab123"\n
'''
