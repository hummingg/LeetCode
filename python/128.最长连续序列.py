#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
# https://leetcode.cn/problems/longest-consecutive-sequence/description/
#
# algorithms
# Medium (55.15%)
# Likes:    1407
# Dislikes: 0
# Total Accepted:    319K
# Total Submissions: 578.7K
# Testcase Example:  '[100,4,200,1,3,2]'
#
# 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
# 
# 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [100,4,200,1,3,2]
# 输出：4
# 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
# 
# 示例 2：
# 
# 
# 输入：nums = [0,3,7,2,5,8,4,6,0,1]
# 输出：9
# 
# 
# 
# 
# 提示：
# 
# 
# 0 
# -10^9 
# 
# 
#

# @lc code=start
class Solution:
    # O(n)?
    # 72: 69.98%(88ms) 10.52%(33.7MB); 95.8%(72ms) 10.64%(33.7MB);
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        sto = set(nums)
        ret = 1
        # st = set()
        for num in sto:
            if num-1 in sto:    # 妙
                continue
            # if num in st:
            #     continue
            # st.add(num)
            cur, n = 0, num
            while n in sto:
                cur += 1
                # st.add(n)
                n += 1
            ret = max(ret, cur)
        return ret
# @lc code=end
'''
[100,4,200,1,3,2]\n
[0,3,7,2,5,8,4,6,0,1]\n
[0,-1]\n
'''
