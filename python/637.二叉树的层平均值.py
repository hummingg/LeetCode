#
# @lc app=leetcode.cn id=637 lang=python3
#
# [637] 二叉树的层平均值
#
# https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
#
# algorithms
# Easy (69.63%)
# Likes:    363
# Dislikes: 0
# Total Accepted:    111.3K
# Total Submissions: 159.9K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 输入：root = [3,9,20,null,null,15,7]
# 输出：[3.00000,14.50000,11.00000]
# 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
# 因此返回 [3, 14.5, 11] 。
# 
# 
# 示例 2:
# 
# 
# 
# 
# 输入：root = [3,9,20,15,7]
# 输出：[3.00000,14.50000,11.00000]
# 
# 
# 
# 
# 提示：
# 
# 
# 
# 
# 树中节点数量在 [1, 10^4] 范围内
# -2^31 <= Node.val <= 2^31 - 1
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
    # 66: 79.27%(52ms) 5.74%(18.2MB);
    def __init__(self):
        self.layers = []
        
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        # 不想写层序遍历了
        self.preOrder(root, 0)
        # print(self.layers)
        return [ layer[0] / layer[1] for layer in self.layers]
        
    def preOrder(self, root: Optional[TreeNode], depth: int) -> None:
        if root is None:
            return
        if len(self.layers) >= depth+1:
            self.layers[depth][0] += root.val
            self.layers[depth][1] += 1
        else:
            self.layers.append([root.val, 1])
        self.preOrder(root.left, depth+1)
        self.preOrder(root.right, depth+1)
# @lc code=end
'''
[3,9,20,null,null,15,7]\n
[3,9,20,15,7]
'''
