/*
 * @lc app=leetcode.cn id=404 lang=csharp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (60.40%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    146.8K
 * Total Submissions: 243K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: root = [3,9,20,null,null,15,7] 
 * 输出: 24 
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 * 
 * 
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
    // 93 16;
    public int SumOfLeftLeaves(TreeNode root) {
        if(root is null){
            return 0;
        }
        int sum;
        if(root.left is not null && root.left.left is null && root.left.right is null){
            sum = root.left.val;
        }else{
            sum = SumOfLeftLeaves(root.left);
        }
        sum += SumOfLeftLeaves(root.right);
        return sum;
    }
}
// @lc code=end

