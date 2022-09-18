#
# @lc app=leetcode.cn id=922 lang=python3
#
# [922] 按奇偶排序数组 II
#
# https://leetcode.cn/problems/sort-array-by-parity-ii/description/
#
# algorithms
# Easy (71.33%)
# Likes:    244
# Dislikes: 0
# Total Accepted:    99.8K
# Total Submissions: 139.9K
# Testcase Example:  '[4,2,5,7]'
#
# 给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
# 
# 对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
# 
# 你可以返回 任何满足上述条件的数组作为答案 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [4,2,5,7]
# 输出：[4,5,2,7]
# 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [2,3]
# 输出：[2,3]
# 
# 
# 
# 
# 提示：
# 
# 
# 2 <= nums.length <= 2 * 10^4
# nums.length 是偶数
# nums 中一半是偶数
# 0 <= nums[i] <= 1000
# 
# 
# 
# 
# 进阶：可以不使用额外空间解决问题吗？
# 
#

from typing import List

# @lc code=start
class Solution:
    # 26 89 64 16; 19 81 68 16.1;
    # 进阶：不使用额外空间，且交换次数最少。三指针
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        even = 1    # 待处理和交换的下一个偶数的索引（始终是奇数）
        odd = 0     # 待处理和交换的下一个奇数的索引（始终是偶数）
        i = 0
        while i < len(nums):
            if i % 2 == 0:
                if nums[i] % 2 == 0:
                    i += 1
                    continue
                # 这是在偶数位置的奇数，与下一个在奇数位置的偶数交换。不会越界。
                while nums[even] % 2 == 1:
                    even += 2
                nums[i], nums[even] = nums[even], nums[i]
                even += 2
            else:
                if nums[i] % 2 == 1:
                    i += 1
                    continue
                # 这是在奇数位置的偶数, 与下一个在偶数位置的奇数交换。不会越界。
                while nums[odd] % 2 == 0:
                    odd += 2
                nums[i], nums[odd] = nums[odd], nums[i]
                odd += 2
            # [0..even-2]中奇数位置都是奇数，[0..odd-2]中偶数位置都是偶数，不用重复判断
            i = max(i+1, min(even, odd) - 1)
        return nums
                    
# @lc code=end
'''
'
[4,2,5,7]\n
[2,3]
'
'''
