#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#
# https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
#
# algorithms
# Easy (54.34%)
# Likes:    263
# Dislikes: 0
# Total Accepted:    138K
# Total Submissions: 253.9K
# Testcase Example:  '"hello"'
#
# 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
# 
# 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：s = "hello"
# 输出："holle"
# 
# 
# 示例 2：
# 
# 
# 输入：s = "leetcode"
# 输出："leotcede"
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 3 * 10^5
# s 由 可打印的 ASCII 字符组成
# 
# 
#

# @lc code=start
class Solution:
    # 480: 66.28%(56ms) 93.4%(16MB);
    def reverseVowels(self, s: str) -> str:
        yuan = list('aeiouAEIOU')
        s = list(s)
        n = len(s)
        low, high = 0, n-1
        while low < high:
            while low < n and s[low] not in yuan:
                low += 1
            while high >= 0 and s[high] not in yuan:
                high -= 1
            if low == n or high == -1 or low >= high:
                break
            # print(low, high)
            # l, h = s[low], s[high]
            # s[low] = h
            # s[high] = l
            s[low], s[high] = s[high], s[low]
            low += 1
            high -= 1
        return ''.join(s)
# @lc code=end
'''
"hello"\n
"leetcode"\n
"a"\n
"b"\n
'''
