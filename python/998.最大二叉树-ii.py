#
# @lc app=leetcode.cn id=998 lang=python3
#
# [998] 最大二叉树 II
#
# https://leetcode.cn/problems/maximum-binary-tree-ii/description/
#
# algorithms
# Medium (62.62%)
# Likes:    66
# Dislikes: 0
# Total Accepted:    9.7K
# Total Submissions: 15.5K
# Testcase Example:  '[4,1,3,null,null,2]\n5'
#
# 最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。
# 
# 给你最大树的根节点 root 和一个整数 val 。
# 
# 就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：
# 
# 
# 如果 a 为空，返回 null 。
# 否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
# root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
# root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
# 返回 root 。
# 
# 
# 请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。
# 
# 假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。
# 
# 返回 Construct(b) 。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 输入：root = [4,1,3,null,null,2], val = 5
# 输出：[5,4,null,1,3,null,null,2]
# 解释：a = [1,4,2,3], b = [1,4,2,3,5]
# 
# 示例 2：
# 
# 
# 
# 输入：root = [5,2,4,null,1], val = 3
# 输出：[5,2,4,null,1,null,3]
# 解释：a = [2,1,5,4], b = [2,1,5,4,3]
# 
# 示例 3：
# 
# 
# 
# 输入：root = [5,2,3,null,1], val = 4
# 输出：[5,2,4,null,1,3]
# 解释：a = [2,1,5,3], b = [2,1,5,3,4]
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点数目在范围 [1, 100] 内
# 1 <= Node.val <= 100
# 树中的所有值 互不相同
# 1 <= val <= 100
# 
# 
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
    # 75: 62.71%(40ms) 82.2%(14.9MB);
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root.val < val:
            return TreeNode(val, root, None)
        node = root
        while node.right:
            if node.right.val < val:
                newNode = TreeNode(val, node.right)
                node.right = newNode
                break
            node = node.right
        if not node.right:
            node.right = TreeNode(val)
        return root
            
# @lc code=end
'''
[4,1,3,null,null,2]\n5\n
[5,2,4,null,1]\n3\n
[5,2,3,null,1]\n4\n
'''
