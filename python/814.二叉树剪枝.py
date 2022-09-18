#
# @lc app=leetcode.cn id=814 lang=python3
#
# [814] 二叉树剪枝
#
# https://leetcode.cn/problems/binary-tree-pruning/description/
#
# algorithms
# Medium (70.23%)
# Likes:    242
# Dislikes: 0
# Total Accepted:    33.3K
# Total Submissions: 46.8K
# Testcase Example:  '[1,null,0,0,1]'
#
# 给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
# 
# 返回移除了所有不包含 1 的子树的原二叉树。
# 
# 节点 node 的子树为 node 本身加上所有 node 的后代。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：root = [1,null,0,0,1]
# 输出：[1,null,0,null,1]
# 解释：
# 只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
# 
# 
# 示例 2：
# 
# 
# 输入：root = [1,0,1,0,0,0,1]
# 输出：[1,null,1,null,1]
# 
# 
# 示例 3：
# 
# 
# 输入：root = [1,1,0,1,1,0,1,0]
# 输出：[1,1,0,1,1,null,1]
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点的数目在范围 [1, 200] 内
# Node.val 为 0 或 1
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
    # 30: 49.47%(40ms) 90.64%(14.8MB);
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        self.pruneTree(root.left)
        self.pruneTree(root.right)
        if root.left and not root.left.left and not root.left.right and root.left.val == 0:
                root.left = None
        if root.right and not root.right.left and not root.right.right and root.right.val == 0:
                root.right = None
        if not root.left and not root.right and root.val == 0:
            root = None
        return root
        
            
# @lc code=end
'''
[1,null,0,0,1]\n
[1,0,1,0,0,0,1]\n
[1,1,0,1,1,0,1,0]\n
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
'''
