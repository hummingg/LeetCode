using System;
/*
 * @lc app=leetcode.cn id=515 lang=csharp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (65.78%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    82.5K
 * Total Submissions: 124.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
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
    // 27 7 144 44.6;
    public IList<int> LargestValues(TreeNode root) {
        var ret = new List<int>();
        if(root == null){
            return ret;
        }
        var oldque = new Queue<TreeNode>();
        oldque.Enqueue(root);
        while(true){
            int mx = int.MinValue;
            var newque = new Queue<TreeNode>(); // 局部变量
            while(oldque.Count > 0){
                var node = oldque.Dequeue();
                mx = Math.Max(mx, node.val);
                if(node.left != null){
                    newque.Enqueue(node.left);
                }
                if(node.right != null){
                    newque.Enqueue(node.right);
                }
            }
            ret.Add(mx);
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
/*
[1,3,2,5,3,null,9]\n
[1,2,3]\n
[]
*/
