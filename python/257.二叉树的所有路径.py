#
# @lc app=leetcode.cn id=257 lang=python3
#
# [257] 二叉树的所有路径
#
# https://leetcode.cn/problems/binary-tree-paths/description/
#
# algorithms
# Easy (70.06%)
# Likes:    793
# Dislikes: 0
# Total Accepted:    234.1K
# Total Submissions: 334.1K
# Testcase Example:  '[1,2,3,null,5]'
#
# 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
# 
# 叶子节点 是指没有子节点的节点。
# 
# 
# 示例 1：
# 
# 
# 输入：root = [1,2,3,null,5]
# 输出：["1->2->5","1->3"]
# 
# 
# 示例 2：
# 
# 
# 输入：root = [1]
# 输出：["1"]
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点的数目在范围 [1, 100] 内
# -100 <= Node.val <= 100
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
    # 208: 77.65%(36ms) 80.64%(14.9MB);
    def __init__(self):
        self._path = []
        self._ret = []
        
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return self._ret
        self._path.append(root)
        if not root.left and not root.right:
            # print('->'.join(list(map(lambda node: str(node.val), self.path))))
            self._ret.append('->'.join(list(map(lambda node: str(node.val), self._path))))
            # print(self.path) [1,2,3,null,5]\n[1]
        if root.left:
            self.binaryTreePaths(root.left)
        if root.right:
            self.binaryTreePaths(root.right)
        self._path.pop()
        return self._ret
        
# @lc code=end

