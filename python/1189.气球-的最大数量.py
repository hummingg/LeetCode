#
# @lc app=leetcode.cn id=1189 lang=python3
#
# [1189] “气球” 的最大数量
#
# https://leetcode.cn/problems/maximum-number-of-balloons/description/
#
# algorithms
# Easy (68.52%)
# Likes:    113
# Dislikes: 0
# Total Accepted:    54.6K
# Total Submissions: 79.6K
# Testcase Example:  '"nlaebolko"'
#
# 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
# 
# 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 输入：text = "nlaebolko"
# 输出：1
# 
# 
# 示例 2：
# 
# 
# 
# 输入：text = "loonbalxballpoon"
# 输出：2
# 
# 
# 示例 3：
# 
# 输入：text = "leetcode"
# 输出：0
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= text.length <= 10^4
# text 全部由小写英文字母组成
# 
# 
#

# @lc code=start
from itertools import count
from typing import Counter


class Solution:
    # 25: 30.24%(44ms) 76.65%(15MB);
    def maxNumberOfBalloons(self, text: str) -> int:
        counter = Counter(text)
        ret = 10 ** 4 + 1
        for key in 'ban':
            if key not in counter.keys():
                return 0
            ret = min([ret, counter.get(key)])
        for key in 'lo':
            if key not in counter.keys():
                return 0
            ret = min([ret, counter.get(key) // 2])
        return ret
            
# @lc code=end
'''
"nlaebolko"\n
"loonbalxballpoon"\n
"leetcode"\n
'''
