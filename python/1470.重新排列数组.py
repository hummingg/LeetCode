#
# @lc app=leetcode.cn id=1470 lang=python3
#
# [1470] 重新排列数组
#
# https://leetcode.cn/problems/shuffle-the-array/description/
#
# algorithms
# Easy (83.84%)
# Likes:    91
# Dislikes: 0
# Total Accepted:    62.2K
# Total Submissions: 74.2K
# Testcase Example:  '[2,5,1,3,4,7]\n3'
#
# 给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。
# 
# 请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。
# 
# 
# 
# 示例 1：
# 
# 输入：nums = [2,5,1,3,4,7], n = 3
# 输出：[2,3,5,4,1,7] 
# 解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
# 
# 
# 示例 2：
# 
# 输入：nums = [1,2,3,4,4,3,2,1], n = 4
# 输出：[1,4,2,3,3,2,4,1]
# 
# 
# 示例 3：
# 
# 输入：nums = [1,1,2,2], n = 2
# 输出：[1,2,1,2]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 500
# nums.length == 2n
# 1 <= nums[i] <= 10^3
# 
# 
#

# @lc code=start
class Solution:
    # 53: 11.59%(52ms) 41.06%(15.1MB);
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        x = n-1
        y = 2*n-2
        while x > 0:
            nums.insert(y, nums.pop(x))
            x -= 1
            y -= 2
        return nums
# @lc code=end
'''
[2,5,1,3,4,7]\n3\n
[1,2,3,4,4,3,2,1]\n4\n
[1,1,2,2]\n2\n
'''
