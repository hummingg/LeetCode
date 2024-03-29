#
# @lc app=leetcode.cn id=1608 lang=python3
#
# [1608] 特殊数组的特征值
#
# https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
#
# algorithms
# Easy (59.37%)
# Likes:    103
# Dislikes: 0
# Total Accepted:    26.2K
# Total Submissions: 43.3K
# Testcase Example:  '[3,5]'
#
# 给你一个非负整数数组 nums 。如果存在一个数 x ，使得 nums 中恰好有 x 个元素 大于或者等于 x ，那么就称 nums 是一个 特殊数组
# ，而 x 是该数组的 特征值 。
# 
# 注意： x 不必 是 nums 的中的元素。
# 
# 如果数组 nums 是一个 特殊数组 ，请返回它的特征值 x 。否则，返回 -1 。可以证明的是，如果 nums 是特殊数组，那么其特征值 x 是 唯一的
# 。
# 
# 
# 
# 示例 1：
# 
# 输入：nums = [3,5]
# 输出：2
# 解释：有 2 个元素（3 和 5）大于或等于 2 。
# 
# 
# 示例 2：
# 
# 输入：nums = [0,0]
# 输出：-1
# 解释：没有满足题目要求的特殊数组，故而也不存在特征值 x 。
# 如果 x = 0，应该有 0 个元素 >= x，但实际有 2 个。
# 如果 x = 1，应该有 1 个元素 >= x，但实际有 0 个。
# 如果 x = 2，应该有 2 个元素 >= x，但实际有 0 个。
# x 不能取更大的值，因为 nums 中只有两个元素。
# 
# 示例 3：
# 
# 输入：nums = [0,4,3,0,4]
# 输出：3
# 解释：有 3 个元素大于或等于 3 。
# 
# 
# 示例 4：
# 
# 输入：nums = [3,6,7,7,0]
# 输出：-1
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 1000
# 
# 
#

# @lc code=start
class Solution:
    # 98: 99.75%(24ms) 37.99%(14.9MB);
    def specialArray(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        if nums[-1] >= len(nums):
            return len(nums)
        # [4, 4, 3, 0, 0]
        for i in range(1, min(len(nums), 101)):
            if nums[i-1]>= i and nums[i] < i:
                return i
        return -1
        
    # 98: 53.59%(40ms) 84.16%(14.8MB);
    def specialArray1(self, nums: List[int]) -> int:
        cnter = Counter(nums)
        keys = list(cnter.keys())
        keys.sort(reverse=True)
        if keys[-1] >= len(nums):
            return len(nums)
        cnt = 0
        for i in range(len(keys)-1):
            key = keys[i]
            next_key = keys[i+1]
            cnt += cnter.get(key)
            if cnt > key:
                return -1   # key越小cnt越大，已经不可能了
            elif cnt == key or cnt > next_key:
                return cnt
        return -1
        
# @lc code=end
'''
[3,5]\n
[0,0]\n
[0,4,3,0,4]\n
[3,6,7,7,0]\n
'''
