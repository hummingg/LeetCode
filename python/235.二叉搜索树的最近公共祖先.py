#
# @lc app=leetcode.cn id=235 lang=python3
#
# [235] 二叉搜索树的最近公共祖先
#
# https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#
# algorithms
# Easy (67.64%)
# Likes:    902
# Dislikes: 0
# Total Accepted:    271.9K
# Total Submissions: 402.1K
# Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
#
# 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
# 
# 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
# 的深度尽可能大（一个节点也可以是它自己的祖先）。”
# 
# 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
# 
# 
# 
# 
# 
# 示例 1:
# 
# 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
# 输出: 6 
# 解释: 节点 2 和节点 8 的最近公共祖先是 6。
# 
# 
# 示例 2:
# 
# 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
# 输出: 2
# 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
# 
# 
# 
# 说明:
# 
# 
# 所有节点的值都是唯一的。
# p、q 为不同节点且均存在于给定的二叉搜索树中。
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from pprint import pp


class Solution:
    # 28: 6%(604ms) 5.27%(30.9MB);
    def __init__(self):
        path = []
        found = False
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.path = []
        self.found = False
            
        self.preOrder(root, p)
        ppath = copy.deepcopy(self.path)
        # ppath = preOrder(root, p, [])
        
        self.path = []
        self.found = False
        self.preOrder(root, q)
        qpath = copy.deepcopy(self.path)
        # qpath = preOrder(root, q, [])
        # print(ppath, qpath)
        # print(len(ppath), len(qpath))
        size = min(len(ppath), len(qpath))
        i = 0
        while i < size:
            if ppath[i].val != qpath[i].val:
                break
            i += 1
        # for i in range(size):
        #     # print(i, ppath[i].val, qpath[i].val)
        #     if ppath[i].val != qpath[i].val:
        #         break
        # print(i)    # 不会自增到 size
        # if i == size:
        #     return ppath[size-1]
        return ppath[i-1]# if ppath[i].val != qpath[i].val else ppath[-1]
    
    def preOrder(self, root: 'TreeNode', node: 'TreeNode'):
        if self.found:
            return
        if root == node:
            self.path.append(root)
            self.found = True
            return self.path
        self.path.append(root)
        if root.left:
            self.preOrder(root.left, node)
        if self.found:
            return
        if root.right:
            self.preOrder(root.right, node)
        if self.found:
            return
        self.path.pop(len(self.path)-1)
        
# @lc code=end
'''
[6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
[2,1]\n1\n2
'''
