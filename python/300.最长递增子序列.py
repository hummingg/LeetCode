#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长递增子序列
#
# https://leetcode.cn/problems/longest-increasing-subsequence/description/
#
# algorithms
# Medium (53.65%)
# Likes:    2590
# Dislikes: 0
# Total Accepted:    550K
# Total Submissions: 1M
# Testcase Example:  '[10,9,2,5,3,7,101,18]'
#
# 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
# 
# 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
# 的子序列。
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [10,9,2,5,3,7,101,18]
# 输出：4
# 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [0,1,0,3,2,3]
# 输出：4
# 
# 
# 示例 3：
# 
# 
# 输入：nums = [7,7,7,7,7,7,7]
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 2500
# -10^4 <= nums[i] <= 10^4
# 
# 
# 
# 
# 进阶：
# 
# 
# 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
# 
# 
#



from typing import List
# @lc code=start

class Solution:
    # 进阶
    def lengthOfLIS(self, nums: List[int]) -> int:
        size = len(nums)
        srtd = [(nums[i], i) for i in range(size)]
        # print(sorted(srtd, key = lambda x:(x[0],x[1])))
        srtd.sort(key=lambda x: (x[0], x[1]))
        print(srtd)
        # TODO
        
        
        
    def lengthOfLIS1(self, nums: List[int]) -> int:
        size = len(nums)
        dp = [None] * size    # dp[i]: nums[0..i] 的最长严格递增子序列的长度
        dp[0] = 1
        
        for i in range(1, size):
            maxlen = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    maxlen = max(maxlen, dp[j] + 1)
                else:
                    maxlen = max(maxlen, dp[j])
            dp[i] = maxlen
            
            # dp[i] = max([dp[j] + 1 if nums[j] < nums[i] else dp[j] for j in range(i)])
            
        # dp = [max([dp[j] + 1 if nums[j] < nums[i] else dp[j] for j in range(i)]) for i in range(1, size)]
        
        # maxlen = 1
        # for length in dp:
        #     maxlen = max(maxlen, length)
        # return maxlen
        return max(dp)
    
        # dp = [1] * len(nums)
        # return max([max( [dp[j] + 1 if nums[j] < nums[i] else dp[j] for j in range(i)] ) for i in range(1, size)])
# @lc code=end
'''
[10,9,2,5,3,7,101,18]\n
[0,1,0,3,2,3]\n
[7,7,7,7,7,7,7]\n
[1]
'''
