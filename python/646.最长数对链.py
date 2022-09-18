#
# @lc app=leetcode.cn id=646 lang=python3
#
# [646] 最长数对链
#
# https://leetcode.cn/problems/maximum-length-of-pair-chain/description/
#
# algorithms
# Medium (58.62%)
# Likes:    274
# Dislikes: 0
# Total Accepted:    37.8K
# Total Submissions: 63.4K
# Testcase Example:  '[[1,2],[2,3],[3,4]]'
#
# 给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
# 
# 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
# 
# 给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
# 
# 
# 
# 示例：
# 
# 
# 输入：[[1,2], [2,3], [3,4]]
# 输出：2
# 解释：最长的数对链是 [1,2] -> [3,4]
# 
# 
# 
# 
# 提示：
# 
# 
# 给出数对的个数在 [1, 1000] 范围内。
# 
# 
#

# @lc code=start
class Solution:
    def __init__(self):
        self.visited = []
        self.pairs = []
        self.size = 0
        self.ret = 0
    
    # 动态规划
    # 205: 28.76%(2036ms) 6.56%(15.4MB); 43.05%(1896ms) 6.95%(15.4MB);
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs = list(set([tuple(pair) for pair in pairs]))
        size = len(pairs)
        pairs.sort()
        dp = [1] * size
        for i in range(size):
            for j in range(i+1, size):
                if pairs[i][1] < pairs[j][0]:
                    dp[j] = max(dp[j], dp[i]+1)
        return max(dp)
    
    # 图的遍历
    # TLE 105/205      
    def findLongestChain9(self, pairs: List[List[int]]) -> int:
        pairs = list(set([tuple(pair) for pair in pairs]))
        size = len(pairs)
        self.size = size
        pairs.sort()
        self.pairs = pairs
        # print(pairs)
        self.adj = {i: set() for i in range(size)} # 图的邻接表
        for i in range(size):
            for j in range(i+1, size):
                if pairs[i][1] < pairs[j][0]:
                    self.adj[i].add(j)
        for i in range(size):
            self.visited = [False] * size
            self.visited[i] = True
            self.dfs(i, 1)  # 以i为源点搜索最大深度
        return self.ret  
        
            
    def dfs(self, i: int, depth: int):
        neighbors = self.adj[i]
        self.ret = max(self.ret, depth)
        for neighbor in neighbors:
            if self.visited[neighbor]:
                continue
            self.visited[neighbor] = True
            self.dfs(neighbor, depth+1)
            self.visited[neighbor] = False  # 回溯
        
            
# @lc code=end

'''
[[1,2], [2,3], [3,4]]\n
[[1,2], [3,4], [2,3], [2,3]]\n

, [2,2]
'''