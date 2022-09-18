/*
 * @lc app=leetcode.cn id=1367 lang=csharp
 *
 * [1367] 二叉树中的列表
 *
 * https://leetcode.cn/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (42.89%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 44K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * 给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
 * 
 * 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False
 * 。
 * 
 * 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 解释：树中蓝色的节点构成了与链表对应的子路径。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：false
 * 解释：二叉树中不存在一一对应链表的路径。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
 * 链表包含的节点数目在 1 到 100 之间。
 * 二叉树包含的节点数目在 1 到 2500 之间。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
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
    // 43 39 116 47.6;
    // 先序遍历+DFS, 可惜没有做到一个函数搞定
    public bool IsSubPath(ListNode head, TreeNode root) {
        if(head == null){
            return true;
        }
        if(root == null){
            return false;
        }
        return Dfs(head, root) || IsSubPath(head, root.left) || IsSubPath(head, root.right);
    }

    public bool Dfs(ListNode head, TreeNode root){
        if(head == null){
            return true;
        }
        if(root == null){
            return false;
        }
        if(head.val != root.val){
            return false;
        }
        return Dfs(head.next, root.left) || Dfs(head.next, root.right);
    }

    ListNode head;
    TreeNode newRoot;
    public bool IsSubPath9(ListNode head, TreeNode root) {
        this.head = head;
        this.newRoot = root;
        return Recur(head, root);
    }

    public bool Recur(ListNode head, TreeNode root) {
        if(head == null){
            return true;
        }
        if(root == null){
            return false;
        }
        Console.WriteLine($"{head.val} {root.val}");
        
        if(head.val == root.val){
            if(Recur(head.next, root.left)){
                return true;
            }
            if(Recur(head.next, root.right)){
                return true;
            }
        }else{
            if(Recur(this.head, newRoot.left)){
                return true;
            }
            if(Recur(this.head, newRoot.right)){
                return true;
            }
        }
        return false;
    }
}
// @lc code=end
/*
[4,2,8]\n
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]\n
[1,4,2,6]\n
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]\n
[1,4,2,6,8]\n
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
*/
