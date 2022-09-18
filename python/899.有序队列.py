#
# @lc app=leetcode.cn id=899 lang=python3
#
# [899] 有序队列
#
# https://leetcode.cn/problems/orderly-queue/description/
#
# algorithms
# Hard (54.30%)
# Likes:    63
# Dislikes: 0
# Total Accepted:    5.7K
# Total Submissions: 10.5K
# Testcase Example:  '"cba"\n1'
#
# 给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。
# 
# 返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：s = "cba", k = 1
# 输出："acb"
# 解释：
# 在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
# 在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
# 
# 
# 示例 2：
# 
# 
# 输入：s = "baaca", k = 3
# 输出："aaabc"
# 解释：
# 在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
# 在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= k <= S.length <= 1000
# s 只由小写字母组成。
# 
# 
#

# @lc code=start
class Solution:
    # 110: 8.04%(772ms) 16.96%(16.1MB);
    # 桶排序：110: 8.04%(2644ms) 20.53%(16MB);
    def orderlyQueue(self, s: str, k: int) -> str:
        size = len(s)
        if k == 1:
            ss = s * 2
            return min([ss[i:size+i] for i in range(size)])
        
        # 110: 50.89%(40ms) 5.36%(16.2MB);
        # return ''.join(sorted(s))
        
        os = '%s' % s   # 复制字符串
        while True:
            # que = list(os[:k])
            # oque = sorted(que)
            buckets = [0] * 26  # 桶排序
            for i in range(k):
                buckets[ord(os[i])-97] += 1
            # print(''.join(que))
            # print(''.join(oque))
            # print(os, ns, ''.join(que), ''.join(oque))
            ns = ''
            for i in range(k, size):
                # small = oque.pop(0)
                # que.remove(small)
                for j in range(26):
                    if buckets[j] > 0:
                        break
                ns += chr(j+97)
                buckets[j] -= 1
                # que.append(os[i])
                # oque.append(os[i])
                # oque.sort()
                buckets[ord(os[i])-97] += 1
                # print(small, ''.join(que), ''.join(oque))
            # small = oque.pop(0)
            # que.remove(small)
            # ns += small
            # for ch in que:
            #     ns += ch
            # while len(oque) > 0:
            #     ns += oque.pop(0)
            for j in range(26):
                ns += chr(j+97) * buckets[j]
            if ns == os:
                break
            os = '%s' % ns
        return ns
            
        
# @lc code=end
'''
"cba"\n1\n
"baaca"\n3\n
"cbacbacba"\n3\n
"gxzv"\n4\n
"aaabbbccc"
'''
