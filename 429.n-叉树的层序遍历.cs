/*
 * @lc app=leetcode.cn id=429 lang=csharp
 *
 * [429] N 叉树的层序遍历
 *
 * https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (72.00%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    119.7K
 * Total Submissions: 166.2K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 * 
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[[1],[3,2,4],[5,6]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树的高度不会超过 1000
 * 树的节点总数在 [0, 10^4] 之间
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {
    // 50 55 168 48.9;
    public IList<IList<int>> LevelOrder(Node root) {
        var ret = new List<IList<int>>(); // 注意类型
        if(root == null){
            return ret;
        }
        var que = new Queue<Node>();
        Node cur;
        que.Enqueue(root);
        while(true){
            var v = new List<int>(); // // 注意类型
            var queNew = new Queue<Node>();
            while(que.Count > 0){
                cur = que.Peek();
                que.Dequeue();
                v.Add(cur.val);
                for(int i = 0; i<cur.children.Count; ++i){
                    queNew.Enqueue(cur.children[i]);
                }
            }
            ret.Add(v);
            if(queNew.Count == 0){
                break;
            }
            que = queNew;
        }
        return ret;
    }
}
// @lc code=end

