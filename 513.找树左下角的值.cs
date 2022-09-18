/*
 * @lc app=leetcode.cn id=513 lang=csharp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.14%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    96.4K
 * Total Submissions: 131.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 
 * 假设二叉树中至少有一个节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [2,1,3]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * ⁠
 * 
 * 
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
    // 31 5 92 40;
    public int FindBottomLeftValue(TreeNode root) {
        var oldque = new Queue<TreeNode>();
        int ret = 0;
        oldque.Enqueue(root);
        while(true){
            ret = oldque.Peek().val;
            var newque = new Queue<TreeNode>();
            while(oldque.Count > 0){
                var node = oldque.Dequeue();
                if(node.left != null){
                    newque.Enqueue(node.left);
                }
                if(node.right != null){
                    newque.Enqueue(node.right);
                }
            }
            if(newque.Count > 0){
                oldque = newque;
            }else{
                break;
            }
        }
        return ret;
    }
}
// @lc code=end

