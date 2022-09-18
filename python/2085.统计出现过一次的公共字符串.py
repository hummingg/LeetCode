#
# @lc app=leetcode.cn id=2085 lang=python3
#
# [2085] 统计出现过一次的公共字符串
#
# https://leetcode.cn/problems/count-common-words-with-one-occurrence/description/
#
# algorithms
# Easy (72.27%)
# Likes:    4
# Dislikes: 0
# Total Accepted:    5.9K
# Total Submissions: 8.2K
# Testcase Example:  '["leetcode","is","amazing","as","is"]\n["amazing","leetcode","is"]'
#
# 给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：words1 = ["leetcode","is","amazing","as","is"], words2 =
# ["amazing","leetcode","is"]
# 输出：2
# 解释：
# - "leetcode" 在两个数组中都恰好出现一次，计入答案。
# - "amazing" 在两个数组中都恰好出现一次，计入答案。
# - "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
# - "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
# 所以，有 2 个字符串在两个数组中都恰好出现了一次。
# 
# 
# 示例 2：
# 
# 
# 输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
# 输出：0
# 解释：没有字符串在两个数组中都恰好出现一次。
# 
# 
# 示例 3：
# 
# 
# 输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
# 输出：1
# 解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= words1.length, words2.length <= 1000
# 1 <= words1[i].length, words2[j].length <= 30
# words1[i] 和 words2[j] 都只包含小写英文字母。
# 
# 
#



# @lc code=start
class Solution:
    # 60: 78.87%(40ms) 47.42%(15.4MB);
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        dict1 = {}
        dict2 = {}
        for word in words1:
            if word not in dict1:
                dict1[word] = 1
            else:
                dict1[word] += 1
        for word in words2:
            if word not in dict2:
                dict2[word] = 1
            else:
                dict2[word] += 1
        ret = 0
        for word in dict1:
            if dict1[word] == 1 and word in dict2 and dict2[word] == 1:
                ret += 1
        return ret
        
# @lc code=end
'''
["leetcode","is","amazing","as","is"]\n["amazing","leetcode","is"]\n
["b","bb","bbb"]\n["a","aa","aaa"]\n
["a","ab"]\n["a","a","a","ab"]
'''
