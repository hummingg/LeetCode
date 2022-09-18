#
# @lc app=leetcode.cn id=593 lang=python3
#
# [593] 有效的正方形
#
# https://leetcode.cn/problems/valid-square/description/
#
# algorithms
# Medium (44.16%)
# Likes:    93
# Dislikes: 0
# Total Accepted:    11.4K
# Total Submissions: 25.7K
# Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
#
# 给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
# 
# 点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。
# 
# 一个 有效的正方形 有四条等边和四个等角(90度角)。
# 
# 
# 
# 示例 1:
# 
# 
# 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
# 输出: True
# 
# 
# 示例 2:
# 
# 
# 输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
# 输出：false
# 
# 
# 示例 3:
# 
# 
# 输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
# 输出：true
# 
# 
# 
# 
# 提示:
# 
# 
# p1.length == p2.length == p3.length == p4.length == 2
# -10^4 <= xi, yi <= 10^4
# 
# 
#
from collections import Counter
# @lc code=start
class Solution:
    # 253: 75.51%(36ms) 8.57%(15.1MB);11.02%(48ms) 24.9%(15.1MB);53.06%(40ms) 64.08%(15MB);96.73%(28ms) 8.16%(15.1MB);
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        p = [p1, p2, p3, p4]
        # 两两连边，得到C(4,2)=6条边
        edges = []
        for i in range(3):
            for j in range(i+1, 4):
                edges.append((p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]))
                # edges.append((p[i][0] - p[j][0]) ** 2 + (p[i][1] - p[j][1]) ** 2)
        counter = Counter(edges)
        keys = list(counter.keys())
        if len(keys) != 2:
            return False
        # print(counter.items())
        # for k in counter.keys():
        #     print(k, counter.get(k))
        cnt1 = counter.get(keys[0])
        cnt2 = counter.get(keys[1])
        return cnt1 == 4 and cnt2 == 2 and keys[0] < keys[1] or cnt1 == 2 and cnt2 == 4 and keys[0] > keys[1]
# @lc code=end
'''
[0,0]\n[1,1]\n[1,0]\n[0,1]\n
[0,0]\n[1,1]\n[1,0]\n[0,12]\n
[1,0]\n[-1,0]\n[0,1]\n[0,-1]\n
'''
