#
# @lc app=leetcode.cn id=412 lang=python3
#
# [412] Fizz Buzz
#
# https://leetcode.cn/problems/fizz-buzz/description/
#
# algorithms
# Easy (70.69%)
# Likes:    205
# Dislikes: 0
# Total Accepted:    140.8K
# Total Submissions: 199.3K
# Testcase Example:  '3'
#
# 给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
# 
# 
# answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
# answer[i] == "Fizz" 如果 i 是 3 的倍数。
# answer[i] == "Buzz" 如果 i 是 5 的倍数。
# answer[i] == i （以字符串形式）如果上述条件全不满足。
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 3
# 输出：["1","2","Fizz"]
# 
# 
# 示例 2：
# 
# 
# 输入：n = 5
# 输出：["1","2","Fizz","4","Buzz"]
# 
# 
# 示例 3：
# 
# 
# 输入：n = 15
# 
# 输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    # 8: 93.42%(32ms) 57.52%(15.5MB);
    def fizzBuzz(self, n: int) -> List[str]:
        ret = [''] * (n+1)
        for i in range(1, n+1):
            if i % 3 == 0:
                if i % 5 == 0:
                    ret[i] = 'FizzBuzz'
                else:
                    ret[i] = 'Fizz'
            elif i % 5 == 0:
                ret[i] = 'Buzz'
            else:
                ret[i] = str(i)
        ret.pop(0)
        return ret
# @lc code=end
'''
3\n
5\n
15\n
'''
