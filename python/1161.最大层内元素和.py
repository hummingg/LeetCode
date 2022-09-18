#
# @lc app=leetcode.cn id=1161 lang=python3
#
# [1161] 最大层内元素和
#
# https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/description/
#
# algorithms
# Medium (62.86%)
# Likes:    59
# Dislikes: 0
# Total Accepted:    13.4K
# Total Submissions: 21.3K
# Testcase Example:  '[1,7,0,7,-8,null,null]'
#
# 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
# 
# 请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 输入：root = [1,7,0,7,-8,null,null]
# 输出：2
# 解释：
# 第 1 层各元素之和为 1，
# 第 2 层各元素之和为 7 + 0 = 7，
# 第 3 层各元素之和为 7 + -8 = -1，
# 所以我们返回第 2 层的层号，它的层内元素之和最大。
# 
# 
# 示例 2：
# 
# 
# 输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
# 输出：2
# 
# 
# 
# 
# 提示：
# 
# 
# 树中的节点数在 [1, 10^4]范围内
# -10^5 <= Node.val <= 10^5
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
    # 40: 18.3%(440ms) 6.54%(19.8MB);
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        layno = 1
        ret = layno
        laySumMax = root.val 
        preLay = [root]
        while len(preLay) > 0:
            curLay = []
            while len(preLay) > 0:
                node = preLay.pop(0)
                if node.left:
                    curLay.append(node.left)
                if node.right:
                    curLay.append(node.right)
            if len(curLay) == 0:
                return ret
            layno += 1
            laySum = reduce(lambda x, y: x + y, list(map(lambda node: node.val, curLay)))
            if laySum > laySumMax:
                laySumMax = laySum
                ret = layno
            preLay = curLay
        return ret
            
        
# @lc code=end

