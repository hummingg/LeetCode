#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#
# https://leetcode.cn/problems/single-number/description/
#
# algorithms
# Easy (72.23%)
# Likes:    2466
# Dislikes: 0
# Total Accepted:    715.3K
# Total Submissions: 990.3K
# Testcase Example:  '[2,2,1]'
#
# 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
# 
# 说明：
# 
# 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
# 
# 示例 1:
# 
# 输入: [2,2,1]
# 输出: 1
# 
# 
# 示例 2:
# 
# 输入: [4,1,2,1,2]
# 输出: 4
# 
#



# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ret = 0
        for num in nums:
            ret ^= num
        return ret
        
# @lc code=end

