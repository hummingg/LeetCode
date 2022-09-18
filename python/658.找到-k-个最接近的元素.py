#
# @lc app=leetcode.cn id=658 lang=python3
#
# [658] 找到 K 个最接近的元素
#
# https://leetcode.cn/problems/find-k-closest-elements/description/
#
# algorithms
# Medium (45.97%)
# Likes:    355
# Dislikes: 0
# Total Accepted:    45.4K
# Total Submissions: 98.4K
# Testcase Example:  '[1,2,3,4,5]\n4\n3'
#
# 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
# 
# 整数 a 比整数 b 更接近 x 需要满足：
# 
# 
# |a - x| < |b - x| 或者
# |a - x| == |b - x| 且 a < b
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：arr = [1,2,3,4,5], k = 4, x = 3
# 输出：[1,2,3,4]
# 
# 
# 示例 2：
# 
# 
# 输入：arr = [1,2,3,4,5], k = 4, x = -1
# 输出：[1,2,3,4]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= k <= arr.length
# 1 <= arr.length <= 10^4
# arr 按 升序 排列
# -10^4 <= arr[i], x <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    # 66: 38.17%(68ms) 55.54%(16.2MB);
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # arr.sort()
        size = len(arr)
        lti = -1
        for i in range(size):
            if arr[i] <= x:
                lti = i
            else:
                break
        begin = lti # 最后一个 <=x 的
        end = lti+1 # 第一个 >x 的
        cnt = 0
        while cnt < k:
            bdiff, ediff = -1, -1
            
            if begin > -1:
                bdiff = abs(arr[begin]-x)
            if end < size:
                ediff = abs(arr[end]-x)
                
            if bdiff == -1:
                end += 1
            elif ediff == -1:
                begin -= 1
            elif bdiff <= ediff:
                begin -= 1
            else:
                end += 1
            
            cnt += 1    # 二分加速？
        return arr[begin+1:end]

# @lc code=end
'''
[1,2,3,4,5]\n4\n3\n
[1,2,3,4,5]\n4\n-1\n
[1,2,3,4,5]\n5\n-1\n
'''
