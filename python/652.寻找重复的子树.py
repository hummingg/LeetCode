#
# @lc app=leetcode.cn id=652 lang=python3
#
# [652] 寻找重复的子树
#
# https://leetcode.cn/problems/find-duplicate-subtrees/description/
#
# algorithms
# Medium (58.78%)
# Likes:    498
# Dislikes: 0
# Total Accepted:    62.6K
# Total Submissions: 105.7K
# Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
#
# 给定一棵二叉树 root，返回所有重复的子树。
# 
# 对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
# 
# 如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 输入：root = [1,2,3,4,null,2,4,null,null,4]
# 输出：[[2,4],[4]]
# 
# 示例 2：
# 
# 
# 
# 
# 输入：root = [2,1,1]
# 输出：[[1]]
# 
# 示例 3：
# 
# 
# 
# 
# 输入：root = [2,2,2,3,null,3,null]
# 输出：[[2,3],[3]]
# 
# 
# 
# 提示：
# 
# 
# 树中的结点数在[1,10^4]范围内。
# -200 <= Node.val <= 200
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
    # 176: 20.54%(76ms) 7.15%(29.1MB);
    def __init__(self):
        self.seen = {}
        
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.preorder(root)
        ret = []
        for k, v in self.seen.items():
            if len(v) < 2:
                continue
            ret.append(v[0])
        return ret
        
    def preorder(self, root: Optional[TreeNode]) -> str:
        if not root:
            return ''
        serial = '(' + str(root.val) + ')(' +  self.preorder(root.left) + ')(' + self.preorder(root.right) + ')'
        if (serial in self.seen):
            self.seen[serial].append(root)
        else:
            self.seen[serial] = [root]
        return serial
    
    
class Solution9:
    def __init__(self):
        self.d = {}

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        # print(self.preorder(root))
        # print(self.midorder(root))
        self.pretravel(root)
        same = []
        for k1, v1 in self.d.items():
            for k2, v2 in self.d.items():
                if k1 == k2:
                    continue
                if v1 == v2:
                    same.append(k1)
        structs = set()
        ret = []
        for node in same:
            curstruct = (tuple(self.d[node][0]), tuple(self.d[node][1]))
            if curstruct  in structs:
                continue
            structs.add(curstruct)
            ret.append(node)
        return ret

    def pretravel(self, root: Optional[TreeNode]):
        if not root:
            return
        self.d[root] = [self.preorder(root), self.midorder(root)]
        self.pretravel(root.left)
        self.pretravel(root.right)

    def preorder(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ret = [root.val]
        ret.extend(self.preorder(root.left))
        ret.extend(self.preorder(root.right))
        return ret

    def midorder(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ret = self.midorder(root.left)
        ret.append(root.val)
        ret.extend(self.midorder(root.right))
        return ret
'''
[1,2,3,4,null,2,4,null,null,4]
[2,1,1]
[2,2,2,3,null,3,null]
[2,2,2,3,null,2,2,null,null,3,null,3,null]
[0,0,0,0,null,null,0,null,null,null,0]
'''
# @lc code=end
'''
[1,2,3,4,null,2,4,null,null,4]\n
[2,1,1]\n
[2,2,2,3,null,3,null]\n
'''