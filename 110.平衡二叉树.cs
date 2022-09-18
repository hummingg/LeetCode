using System;
/*
 * @lc app=leetcode.cn id=110 lang=csharp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (57.03%)
 * Likes:    1023
 * Dislikes: 0
 * Total Accepted:    363.9K
 * Total Submissions: 637.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    // 46 33; 65 77 96 42;
    public bool isBalanced = true;
    public bool IsBalanced(TreeNode root) {
        RecurHeight(root);
        return isBalanced;
    }

    public int RecurHeight(TreeNode root){
        if(root == null || !isBalanced){
            return 0;
        }
        int leftH = RecurHeight(root.left);
        int rightH = RecurHeight(root.right);
        if(Math.Abs(leftH - rightH) > 1){
            isBalanced = false;
        }
        return 1 + Math.Max(leftH, rightH);
    }
}
// @lc code=end
/*
[3,9,20,null,null,15,7]\n
[1,2,2,3,3,null,null,4,4]\n
[]
*/
