#
# @lc app=leetcode.cn id=1002 lang=python3
#
# [1002] 查找共用字符
#
# https://leetcode.cn/problems/find-common-characters/description/
#
# algorithms
# Easy (71.95%)
# Likes:    276
# Dislikes: 0
# Total Accepted:    68.4K
# Total Submissions: 95.1K
# Testcase Example:  '["bella","label","roller"]'
#
# 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序
# 返回答案。
# 
# 
# 示例 1：
# 
# 
# 输入：words = ["bella","label","roller"]
# 输出：["e","l","l"]
# 
# 
# 示例 2：
# 
# 
# 输入：words = ["cool","lock","cook"]
# 输出：["c","o"]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] 由小写英文字母组成
# 
# 
#



# @lc code=start
class Solution:
    # 83: 70.01%(52ms) 33.6%(15.1MB);
    def commonChars(self, words: List[str]) -> List[str]:
        dicts = []
        for word in words:
            d = {}
            for c in word:
                if c not in d:
                    d[c] = 1
                else:
                    d[c] += 1
            dicts.append(d)
        ret = []
        for c in range(0, 26):
            c = chr(c+97)
            count = 100
            for d in dicts:
                if c not in d:
                    count = 0
                    break
                else:
                    count = min(count, d[c])
            ret.extend([c] * count)
        return ret
# @lc code=end

