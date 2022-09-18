#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#
# https://leetcode.cn/problems/uncommon-words-from-two-sentences/description/
#
# algorithms
# Easy (71.87%)
# Likes:    160
# Dislikes: 0
# Total Accepted:    43.9K
# Total Submissions: 61K
# Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
#
# 句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。
# 
# 如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。
# 
# 给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。
# 
# 
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：s1 = "this apple is sweet", s2 = "this apple is sour"
# 输出：["sweet","sour"]
# 
# 
# 示例 2：
# 
# 
# 输入：s1 = "apple apple", s2 = "banana"
# 输出：["banana"]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s1.length, s2.length <= 200
# s1 和 s2 由小写英文字母和空格组成
# s1 和 s2 都不含前导或尾随空格
# s1 和 s2 中的所有单词间均由单个空格分隔
# 
# 
#



# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l1 = s1.split(" ")
        l2 = s2.split(" ")
        d1 = {}
        for word in l1:
            d1[word] = l1.count(word)
        d2 = {}
        for word in l2:
            d2[word] = l2.count(word)
        ret = []
        for word in d1:
            if d1[word] == 1 and word not in d2:
                ret.append(word)
        for word in d2:
            if d2[word] == 1 and word not in d1:
                ret.append(word)
        return ret
# @lc code=end
'''
'
"this apple is sweet"\n"this apple is sour"\n
"apple apple"\n"banana"
'
'''
