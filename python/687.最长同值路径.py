#
# @lc app=leetcode.cn id=687 lang=python3
#
# [687] 最长同值路径
#
# https://leetcode.cn/problems/longest-univalue-path/description/
#
# algorithms
# Medium (45.39%)
# Likes:    619
# Dislikes: 0
# Total Accepted:    52.3K
# Total Submissions: 114.2K
# Testcase Example:  '[5,4,5,1,1,null,5]'
#
# 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
# 
# 两个节点之间的路径长度 由它们之间的边数表示。
# 
# 
# 
# 示例 1:
# 
# 
# 
# 
# 输入：root = [5,4,5,1,1,5]
# 输出：2
# 
# 
# 示例 2:
# 
# 
# 
# 
# 输入：root = [1,4,5,4,4,5]
# 输出：2
# 
# 
# 
# 
# 提示:
# 
# 
# 树的节点数的范围是 [0, 10^4] 
# -1000 <= Node.val <= 1000
# 树的深度将不超过 1000 
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 当图处理
    def __init__(self):
        self.length = 0
    
    # TLE?No!
    # 71: 5.14%(656ms) 65.75%(19.1MB);    
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        if root:
            self.preorder(root)
        return self.length
        
    def preorder(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root, 0)
        self.preorder(root.left)
        self.preorder(root.right)
    
    # 以 root 为根的同值路径长度
    def dfs(self, root: Optional[TreeNode], length: int) -> int:
        if not root:
            return length-1
        if not root.left and not root.right:
            return length
        left, right = 0, 0
        if root.left and root.left.val == root.val:
            left = self.dfs(root.left, length+1) - length
        if root.right and root.right.val == root.val:
            right = self.dfs(root.right, length+1) - length
        self.length = max(self.length, left + right)
        return length + max(left, right)
        
        
# @lc code=end
'''
[5,4,5,1,1,5]
[1,4,5,4,4,5]
'''
