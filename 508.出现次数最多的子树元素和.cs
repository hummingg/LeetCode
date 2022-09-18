using System;
using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=508 lang=csharp
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode.cn/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (68.70%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 27.6K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 * 
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: root = [5,2,-5]
 * 输出: [2]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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
    // 33 58 144 44.6;
    Dictionary<int,int> dic;
    public int[] FindFrequentTreeSum(TreeNode root) {
        dic = new Dictionary<int,int>();
        Postorder(root);
        int freq = 0;
        foreach(var kvp in dic){
            // Console.WriteLine($"{kvp.Key}: {kvp.Value}");
            freq = Math.Max(freq, kvp.Value);
        }
        var lst = new List<int>();
        foreach(var kvp in dic){
            if(kvp.Value == freq){
                lst.Add(kvp.Key);
            }
        }
        return lst.ToArray();
    }

    void Postorder(TreeNode root){
        if(root == null){
            return;
        }

        Postorder(root.left);
        Postorder(root.right);

        int sum = root.val;
        if(root.left != null){
            sum += root.left.val;
        }
        if(root.right != null){
            sum += root.right.val;
        }
        root.val = sum;
        if(dic.ContainsKey(sum)){
            ++dic[sum];
        }else{
            dic.Add(sum, 1);
        }
    }
}
// @lc code=end
/*
[5,2,-5]
*/
