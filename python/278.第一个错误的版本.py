#
# @lc app=leetcode.cn id=278 lang=python3
#
# [278] 第一个错误的版本
#
# https://leetcode.cn/problems/first-bad-version/description/
#
# algorithms
# Easy (45.63%)
# Likes:    783
# Dislikes: 0
# Total Accepted:    384.1K
# Total Submissions: 841.8K
# Testcase Example:  '5\n4'
#
# 
# 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
# 
# 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
# 
# 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version
# 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
# 
# 
# 示例 1：
# 
# 
# 输入：n = 5, bad = 4
# 输出：4
# 解释：
# 调用 isBadVersion(3) -> false 
# 调用 isBadVersion(5) -> true 
# 调用 isBadVersion(4) -> true
# 所以，4 是第一个错误的版本。
# 
# 
# 示例 2：
# 
# 
# 输入：n = 1, bad = 1
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 1 
# 
# 
#

# @lc code=start
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    # 二分查找
    # 24: 65.79%(36ms) 54.64%(14.8MB);
    def firstBadVersion(self, n: int) -> int:
        low, high = 1, n
        while low <= high:
            mid = (low + high) // 2
            if isBadVersion(mid):
                high = mid-1    # high正确时mid肯定正确，所以low会来到high且正确，然后high是正确，low+=1是错误
            else:
                low = mid+1     # low错误时mid肯定错误，所以high会来到low且错误，然后high-=1是正确，low是错误
        return low
# @lc code=end
'''
5\n4\n
1\n1\n
'''
