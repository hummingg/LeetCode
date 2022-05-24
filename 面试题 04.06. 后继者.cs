/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    TreeNode prevMid = null;    // 中序前驱结点
    // 11 78; 78 89;
    public TreeNode InorderSuccessor(TreeNode root, TreeNode p) {
        if(root == null){
            return null;
        }
        TreeNode ret = InorderSuccessor(root.left, p);

        if(ret != null){
            return ret;
        }
        // if(prevMid != null){
        //     Console.WriteLine(prevMid.val);
        // }
        // Console.WriteLine(root.val);
        if(prevMid == p){
            return root;
        }
        prevMid = root;
        
        return InorderSuccessor(root.right, p);
    }
}