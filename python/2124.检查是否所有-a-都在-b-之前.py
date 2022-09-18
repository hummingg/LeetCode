#
# @lc app=leetcode.cn id=2124 lang=python3
#
# [2124] 检查是否所有 A 都在 B 之前
#
# https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/description/
#
# algorithms
# Easy (70.02%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    9.6K
# Total Submissions: 13.7K
# Testcase Example:  '"aaabbb"'
#
# 给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个  'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回
# false 。
# 
# 
# 
# 示例 1：
# 
# 输入：s = "aaabbb"
# 输出：true
# 解释：
# 'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
# 因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
# 
# 
# 示例 2：
# 
# 输入：s = "abab"
# 输出：false
# 解释：
# 存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
# 因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
# 
# 
# 示例 3：
# 
# 输入：s = "bbb"
# 输出：true
# 解释：
# 不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 100
# s[i] 为 'a' 或 'b'
# 
# 
#

# @lc code=start
class Solution:
    # 216: 45.27%(40ms) 54.73%(14.9MB);
    def checkString(self, s: str) -> bool:
        last_a = s.rfind('a')
        if last_a == -1:
            return True
        first_b = s.find('b')
        if first_b == -1:
            return True
        # print(last_a, first_b)
        return last_a < first_b
# @lc code=end
'''
"aaabbb"\n
"abab"\n
"bbb"\n
'''
