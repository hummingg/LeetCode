/*
 * @lc app=leetcode.cn id=450 lang=csharp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (50.85%)
 * Likes:    767
 * Dislikes: 0
 * Total Accepted:    114.7K
 * Total Submissions: 225.6K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 
 * 一般来说，删除节点可分为两个步骤：
 * 
 * 
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 * 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 * 解释: 二叉树不包含值为 0 的节点
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: root = [], key = 0
 * 输出: []
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数的范围 [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 节点值唯一
 * root 是合法的二叉搜索树
 * -10^5 <= key <= 10^5
 * 
 * 
 * 
 * 
 * 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
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
    // 65 70;
    TreeNode pre, target, targetParent, replace, replaceParent;
    int key;
    // bool found = false;
    public TreeNode DeleteNode(TreeNode root, int key) {
        // 搜索
        TreeNode parent = null, current = root;
        while(current != null && current.val != key){
            parent = current;
            if(current.val < key){
                current = current.right;
            }else{
                current = current.left;
            }
        }
        if(current == null){
            return root;
        }
        
        // 1. 删除叶子结点
        if(current.left == null && current.right == null){
            if(current == root){
                return null;
            }
            if(parent.left != null && parent.left.val == key){
                parent.left = null;
            }else{
                parent.right = null;
            }
            return root;
        }
        // 2. 删除内部结点，找替换用的中序邻居
        TreeNode neighbor, neighborParent = current;
        if(neighborParent.left != null){
            // 找中序前驱
            neighbor = neighborParent.left;
            if(neighbor.right != null){
                while(neighbor.right != null){
                    neighborParent = neighbor;
                    neighbor = neighbor.right;
                }
            }
        }else{
            // 找中序后继
            neighbor = neighborParent.right;
            if(neighbor.left != null){
                while(neighbor.left != null){
                    neighborParent = neighbor;
                    neighbor = neighbor.left;
                }
            }
        }
        // Console.WriteLine($"{current.val} {neighborParent.val} {neighbor.val}");
        current.val = neighbor.val; // 替换
        if(neighborParent == current){
            if(neighbor == neighborParent.left){
                neighborParent.left = neighbor.left;
            }else{
                neighborParent.right = neighbor.right;
            }
        }else{
            if(neighbor == neighborParent.left){
                neighborParent.left = neighbor.right;
            }else{
                neighborParent.right = neighbor.left;
            }
        }
        return current == root ? current : root;
    }

    public TreeNode DeleteNode8(TreeNode root, int key) {
        this.key = key;
        Midorder(root);
        // Console.WriteLine($"{pre.val}");
        if(target == null){
            return root;
        }
        TreeNode next;
        if(target.right != null){
            next = target.right;
            while(next.left != null){
                next = next.left;
            }
        }
        // Console.WriteLine($"{target.val}");
        return root;
    }
    public void Midorder(TreeNode root){
        if(target != null || root == null){
            return;
        }
        Midorder(root.left);
        if(target != null){
            return;
        }
        // Console.WriteLine($"{root.val}");
        if(root.val == key){
            target = root;
            // found = true;
            return;
        }else{
            pre = root;
            Console.WriteLine($"{pre.val}");
        }
        Midorder(root.right);
    }
}
// @lc code=end
/*
[5,3,6,2,4,null,7]\n3\n
[5,3,6,2,4,null,7]\n0\n
[]\n0\n
[4,null,7,6,8,5,null,null,9]\n7\n
[8,0,31,null,6,28,45,1,7,25,30,32,49,null,4,null,null,9,26,29,null,null,42,47,null,2,5,null,12,null,27,null,null,41,43,46,48,null,3,null,null,10,19,null,null,33,null,null,44,null,null,null,null,null,null,null,11,18,20,null,37,null,null,null,null,14,null,null,22,36,38,13,15,21,24,34,null,null,39,null,null,null,16,null,null,23,null,null,35,null,40,null,17]\n1

*/
