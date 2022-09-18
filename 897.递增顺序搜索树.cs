/*
 * @lc app=leetcode.cn id=897 lang=csharp
 *
 * [897] 递增顺序搜索树
 *
 * https://leetcode.cn/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (74.16%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 93.8K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * 给你一棵二叉搜索树的 root ，请你 按中序遍历
 * 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的取值范围是 [1, 100]
 * 0 <= Node.val <= 1000
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
    // 100% 51.28% 72ms 37.1MB 38
    public TreeNode prev = null, newRoot = null;
    public TreeNode IncreasingBST(TreeNode root) {
        Inorder(root);
        // prev.left = null;
        // prev.right = null;
        // Inorderer(root);    // 说明改变了原树
        return newRoot;
    }

    public void Inorder(TreeNode root){
        if(root == null){
            return;
        }
        Inorder(root.left);
        if(prev != null){
            prev.right = root;
            prev = root;    // 是指针？！
            prev.left = null;
        }else{
            prev = root;
            prev.left = null;
            newRoot = prev;
        }
        Inorder(root.right);
    }

    public void Inorderer(TreeNode root){
        if(root == null){
            return;
        }
        Inorderer(root.left);
        Console.WriteLine(root.val);
        Inorderer(root.right);
    }
}
// @lc code=end

