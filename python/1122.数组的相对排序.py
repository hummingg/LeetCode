#
# @lc app=leetcode.cn id=1122 lang=python3
#
# [1122] 数组的相对排序
#
# https://leetcode.cn/problems/relative-sort-array/description/
#
# algorithms
# Easy (70.84%)
# Likes:    227
# Dislikes: 0
# Total Accepted:    76.7K
# Total Submissions: 108.2K
# Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
#
# 给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都出现在 arr1 中。
# 
# 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1
# 的末尾。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
# 输出：[2,2,2,1,4,3,3,9,6,7,19]
# 
# 
# 示例  2:
# 
# 
# 输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
# 输出：[22,28,8,6,17,44]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= arr1.length, arr2.length <= 1000
# 0 <= arr1[i], arr2[i] <= 1000
# arr2 中的元素 arr2[i]  各不相同 
# arr2 中的每个元素 arr2[i] 都出现在 arr1 中
# 
# 
#

# @lc code=start
class Solution:
    # 16: 10.08%(56ms) 5.38%(15.2MB);14.09%(52ms) 51.09%(15MB);6.99%(60ms) 99.08%(14.9MB);
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        tail = 0
        size = len(arr1)
        for num in arr2:
            for i in range(size):
                if arr1[i] == num:
                    arr1.pop(i)
                    arr1.insert(tail, num)
                    tail += 1
        ret = arr1[:tail]
        ret.extend(sorted(arr1[tail:]))
        return ret
                
# @lc code=end

