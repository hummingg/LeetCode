#
# @lc app=leetcode.cn id=662 lang=python3
#
# [662] 二叉树最大宽度
#
# https://leetcode.cn/problems/maximum-width-of-binary-tree/description/
#
# algorithms
# Medium (41.23%)
# Likes:    408
# Dislikes: 0
# Total Accepted:    53.6K
# Total Submissions: 129.7K
# Testcase Example:  '[1,3,2,5,3,null,9]'
#
# 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。
# 
# 树的 最大宽度 是所有层中最大的 宽度 。
# 
# 
# 
# 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null
# 节点，这些 null 节点也计入长度。
# 
# 题目数据保证答案将会在  32 位 带符号整数范围内。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：root = [1,3,2,5,3,null,9]
# 输出：4
# 解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
# 
# 
# 示例 2：
# 
# 
# 输入：root = [1,3,2,5,null,null,9,6,null,7]
# 输出：7
# 解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
# 
# 
# 示例 3：
# 
# 
# 输入：root = [1,3,2,5]
# 输出：2
# 解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点的数目范围是 [1, 3000]
# -100 <= Node.val <= 100
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
    # 114: 8.01%(64ms) 10.68%(19.8MB);
    def __init__(self):
        self.d = {}
        
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.preorder(root, 0, 1)  # 根节点是第0层，编号为1
        ret = 1
        for key in self.d:
            if len(self.d[key]) != 2:
                continue
            ret = max([ret, self.d[key][1] - self.d[key][0] + 1])
        return ret
        
    def preorder(self, root: Optional[TreeNode], depth: int, id: int):
        if not root:
            return
        if depth not in self.d:
            self.d[depth] = [id]
        else:
            if len(self.d[depth]) == 1:
                self.d[depth].append(id)
            else:
                self.d[depth][1] = id
        self.preorder(root.left, depth+1, 2 * id)
        self.preorder(root.right, depth+1, 2 * id + 1)
        
        
    def widthOfBinaryTree0(self, root: Optional[TreeNode]) -> int:
        ret = 0
        queue = [root]
        while len(queue)>0:
            # for node in queue:
            #     if node is None:
            #         print('None')
            #     else:
            #         print(node.val)
            # print('#'*50)
            begin, end = -1, -1
            for i in range(len(queue)):
                if queue[i] is not None:
                    begin = i
                    break
            for i in range(len(queue)-1, -1, -1):
                if queue[i] is not None:
                    end = i
                    break
            if begin == -1:
                break
            ret = max([ret, end-begin+1])
            nque = []
            while len(queue)>0:
                node = queue.pop(0)
                if node is None:
                    nque.append(None)
                    nque.append(None)
                else:
                    nque.append(node.left)
                    nque.append(node.right)
            queue = nque
        return ret
# @lc code=end
'''
[1,3,2,5,3,null,9]\n
[1,3,2,5,null,null,9,6,null,7]\n
[1,3,2,5]\n
'''
