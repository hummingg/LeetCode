#
# @lc app=leetcode.cn id=2259 lang=python3
#
# [2259] 移除指定数字得到的最大结果
#
# https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/description/
#
# algorithms
# Easy (49.25%)
# Likes:    13
# Dislikes: 0
# Total Accepted:    9.1K
# Total Submissions: 18.4K
# Testcase Example:  '"123"\n"3"'
#
# 给你一个表示某个正整数的字符串 number 和一个字符 digit 。
# 
# 从 number 中 恰好 移除 一个 等于 digit 的字符后，找出并返回按 十进制 表示 最大 的结果字符串。生成的测试用例满足 digit 在
# number 中出现至少一次。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：number = "123", digit = "3"
# 输出："12"
# 解释："123" 中只有一个 '3' ，在移除 '3' 之后，结果为 "12" 。
# 
# 
# 示例 2：
# 
# 
# 输入：number = "1231", digit = "1"
# 输出："231"
# 解释：可以移除第一个 '1' 得到 "231" 或者移除第二个 '1' 得到 "123" 。
# 由于 231 > 123 ，返回 "231" 。
# 
# 
# 示例 3：
# 
# 
# 输入：number = "551", digit = "5"
# 输出："51"
# 解释：可以从 "551" 中移除第一个或者第二个 '5' 。
# 两种方案的结果都是 "51" 。
# 
# 
# 
# 
# 提示：
# 
# 
# 2 <= number.length <= 100
# number 由数字 '1' 到 '9' 组成
# digit 是 '1' 到 '9' 中的一个数字
# digit 在 number 中出现至少一次
# 
# 
#



# @lc code=start
class Solution:
    # 17 23 44 15
    def removeDigit(self, number: str, digit: str) -> str:
        ret = ""
        for i in range(len(number)):
            if number[i] == digit:
                ret = max(ret, number[:i] + number[i+1:])
        return ret
# @lc code=end
'''
'
"123"\n"3"\n
"1231"\n"1"\n
"551"\n"5"
'
'''
