#
# @lc app=leetcode.cn id=324 lang=python3
#
# [324] 摆动排序 II
#
# https://leetcode.cn/problems/wiggle-sort-ii/description/
#
# algorithms
# Medium (38.64%)
# Likes:    355
# Dislikes: 0
# Total Accepted:    34.9K
# Total Submissions: 90.3K
# Testcase Example:  '[1,5,1,1,6,4]'
#
# 给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
# 
# 你可以假设所有输入数组都可以得到满足题目要求的结果。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [1,5,1,1,6,4]
# 输出：[1,6,1,5,1,4]
# 解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [1,3,2,2,3,1]
# 输出：[2,3,1,3,1,2]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 
# 0 
# 题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
# 
# 
# 
# 
# 进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
# 
#

# @lc code=start
class Solution:
    # 51 76 56 16; 89 64 44 16;
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        nums[0] < nums[1] > nums[2] < nums[3]...
        no '='
        """
        numscp = copy.copy(nums)
        numscp.sort()
        # print(nums[3])
        # print(numscp[3])
        
        size = len(nums)
        if size == 1:
            return
        
        begin, end = 0, size - 1
        for i in range(size):
            if i % 2 == 0:
                nums[i] = numscp[begin]
                begin += 1
            else:
                nums[i] = numscp[end]
                end -= 1
        
        # 最后几个可能相等，每隔一个修改
        begin, end = size - 1, size - 1
        while nums[begin] == nums[end]:
            begin -= 1
        begin += 1
        if begin == end:
            return
        if (end - begin) % 2 == 0:
            begin += 1
        target = 0 if begin % 2 == 0 else 1
        
        while begin < size:
            # if nums[begin] != nums[target]:
            nums[begin], nums[target] = nums[target], nums[begin]
            # else:
            #     nums[begin-1], nums[target-1] = nums[target-1], nums[begin-1]
            begin += 2
            target += 2
        # print(nums)
            
# @lc code=end
'''
[1,5,1,1,6,4]\n
[1,3,2,2,3,1]\n
[1,1,1,1,1,2,6,4,5,3]\n
[1]\n
[2,1]\n
[1,1,2,1,2,2,1]\n
[1,4,3,4,1,2,1,3,1,3,2,3,3]\n
[5,3,1,2,6,7,8,5,5]\n
[5,3,1,2,6,7,8,5,5,5]\n
[4,5,5,6]\n
[2,3,3,2,2,2,1,1]\n
[0,1,0,6,2,2,2,2]
'''
