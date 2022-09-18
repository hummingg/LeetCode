/*
 * @lc app=leetcode.cn id=1022 lang=csharp
 *
 * [1022] 从根到叶的二进制数之和
 *
 * https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (71.43%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 59.6K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
 * 
 * 
 * 例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 * 
 * 
 * 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 * 
 * 返回这些数字之和。题目数据保证答案是一个 32 位 整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,0,1,0,1,0,1]
 * 输出：22
 * 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在 [1, 1000] 范围内
 * Node.val 仅为 0 或 1 
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
    // 78 100;
    public int sum = 0;
    public int SumRootToLeaf(TreeNode root) {
        Recur(root, 0);
        return sum;
    }
    public void Recur(TreeNode root, int partSum){
        if(root == null){
            return;
        }
        int newPartSum = (partSum << 1) + root.val;
        if(root.left == null && root.right == null){
            sum += newPartSum;
            return;
        }
        Recur(root.left, newPartSum);
        Recur(root.right, newPartSum);
    }
}
// @lc code=end

