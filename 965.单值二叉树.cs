/*
 * @lc app=leetcode.cn id=965 lang=csharp
 *
 * [965] 单值二叉树
 *
 * https://leetcode-cn.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (68.73%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    40.5K
 * Total Submissions: 58.9K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
    int val;    // 递归使用
    // 87 10;
    // 层次遍历
    public bool IsUnivalTree(TreeNode root) {
        Queue<TreeNode> que = new Queue<TreeNode>();
        que.Enqueue(root);
        int val = root.val;
        while(que.Count != 0){
            var parent = que.Dequeue();
            var node = parent.left;
            if(node != null){
                if(node.val != val){
                    return false;
                }else{
                   que.Enqueue(node); 
                }
            }
            node = parent.right;
            if(node != null){
                if(node.val != val){
                    return false;
                }else{
                   que.Enqueue(node); 
                }
            }
        }
        return true;
    }

    // 74 6; 74 10; 87 32; 58 16; 58 87; 10 10; 389 16;
    // 先序遍历
    public bool IsUnivalTree1(TreeNode root) {
        val = root.val;
        return preOrder(root);
    }
    public bool preOrder(TreeNode root) {
        if(root == null){
            return true;
        }
        if(root.val != val){
            return false;
        }
        return preOrder(root.left) && preOrder(root.right);
    }
}
// @lc code=end

