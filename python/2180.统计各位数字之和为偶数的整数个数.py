#
# @lc app=leetcode.cn id=2180 lang=python3
#
# [2180] 统计各位数字之和为偶数的整数个数
#
# https://leetcode.cn/problems/count-integers-with-even-digit-sum/description/
#
# algorithms
# Easy (64.68%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    9.9K
# Total Submissions: 15.4K
# Testcase Example:  '4'
#
# 给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。
# 
# 正整数的 各位数字之和 是其所有位上的对应数字相加的结果。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：num = 4
# 输出：2
# 解释：
# 只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。    
# 
# 
# 示例 2：
# 
# 
# 输入：num = 30
# 输出：14
# 解释：
# 只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是： 
# 2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= num <= 1000
# 
# 
#

# @lc code=start


class Solution:
    # 71: 92.67%(36ms) 39.79%(14.9MB);
    def countEven(self, num: int) -> int:
        # 数学？
        # 0 2 4 6 8
        # 11 13 15 17 19
        # 20 22 24 26 28
        # 31
        tens = num // 10
        ret = 5 * tens - 1
        sumd = 0
        while tens > 0:
            sumd += tens % 10
            tens //= 10
        num %= 10
        if sumd % 2 == 0:
            return ret + num // 2 + 1
        return ret + (num+1)//2
        
# @lc code=end

