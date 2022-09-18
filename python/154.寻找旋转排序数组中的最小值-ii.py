#
# @lc app=leetcode.cn id=154 lang=python3
#
# [154] 寻找旋转排序数组中的最小值 II
#
# https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/
#
# algorithms
# Hard (52.88%)
# Likes:    526
# Dislikes: 0
# Total Accepted:    148.9K
# Total Submissions: 281.5K
# Testcase Example:  '[1,3,5]'
#
# 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7]
# 在变化后可能得到：
# 
# 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
# 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
# 
# 
# 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2],
# ..., a[n-2]] 。
# 
# 给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
# 
# 你必须尽可能减少整个过程的操作步骤。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [1,3,5]
# 输出：1
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [2,2,2,0,1]
# 输出：0
# 
# 
# 
# 
# 提示：
# 
# 
# n == nums.length
# 1 <= n <= 5000
# -5000 <= nums[i] <= 5000
# nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
# 
# 
# 
# 
# 进阶：这道题与 寻找旋转排序数组中的最小值 类似，但 nums 可能包含重复元素。允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
# 
#

# @lc code=start
class Solution:
    # 193: 16.66%(44ms) 95.47%(15.2MB);
    def findMin(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1
        while low < high:
            if nums[low] < nums[high]:
                return nums[low]
            mid = (low + high) // 2 # low <= mid < high
            if nums[low] == nums[mid]:
                # low <= mid < high
                low += 1
            elif nums[low] < nums[mid]:
                # low < mid < high
                low = mid + 1
            else:
                # low < mid < high
                low += 1
                high = mid
                # low <= high
        return nums[low]    # low == high ?
        
# @lc code=end
'''
[1,3,5]\n
[2,2,2,0,1]\n
'''
