#
# @lc app=leetcode.cn id=1103 lang=python3
#
# [1103] 分糖果 II
#
# https://leetcode.cn/problems/distribute-candies-to-people/description/
#
# algorithms
# Easy (63.73%)
# Likes:    107
# Dislikes: 0
# Total Accepted:    40.7K
# Total Submissions: 63.8K
# Testcase Example:  '7\n4'
#
# 排排坐，分糖果。
# 
# 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。
# 
# 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
# 
# 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。
# 
# 
# 重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
# 
# 返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i
# 个小朋友分到的糖果数）。
# 
# 
# 
# 示例 1：
# 
# 输入：candies = 7, num_people = 4
# 输出：[1,2,3,1]
# 解释：
# 第一次，ans[0] += 1，数组变为 [1,0,0,0]。
# 第二次，ans[1] += 2，数组变为 [1,2,0,0]。
# 第三次，ans[2] += 3，数组变为 [1,2,3,0]。
# 第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
# 
# 
# 示例 2：
# 
# 输入：candies = 10, num_people = 3
# 输出：[5,2,3]
# 解释：
# 第一次，ans[0] += 1，数组变为 [1,0,0]。
# 第二次，ans[1] += 2，数组变为 [1,2,0]。
# 第三次，ans[2] += 3，数组变为 [1,2,3]。
# 第四次，ans[0] += 4，最终数组变为 [5,2,3]。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= candies <= 10^9
# 1 <= num_people <= 1000
# 
# 
#

# @lc code=start
class Solution:
    # 27: 80.81%(40ms) 5.05%(15.2MB);
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #    1*(rounds-1)+(rounds-1)*rounds//2
        # 0: 1     2 ...   n
        # 1: n+1   n+2     2n
        # 2: 2n+1   2n+2     3n
        # n(n+1)/2 + n^2*0      n(n+1)/2 + n^2*1  n(n+1)/2 + n^2*2  ... n(n+1)/2 + n^2*[i]  delta
        # n(n+1)/2*(i+1) + n^2*(i(i+1)/2) + delta = candies
        # n(i+1)/2*[(n+1)+(n*i)] + delta = candies
        rounds, major = 0, 0
        # for i in range(num_people):
        i = 0
        while True:
            spent = num_people * (i+1) * (num_people+1+num_people*i) // 2
            if spent > candies:
                rounds = i  # 第 rounds 回分配完成
                break
            else:
                major = spent
                i += 1
        rest = candies - major
        first = 1+num_people*rounds # 第 rounds 回第一个人
        # print(major, rounds, first)
        ret = [max(0, (i+1)*rounds+num_people*(rounds-1)*rounds//2) for i in range(num_people)]
        for i in range(num_people):
            delta = min(rest, first + i)
            ret[i] += delta
            rest -= delta
            if rest == 0:
                break
        return ret
            
# @lc code=end
'''
7\n4\n
10\n3\n
1\n3\n
60\n4\n

1   2   3   4
5   6   7   8
9   10  11  12
'''
