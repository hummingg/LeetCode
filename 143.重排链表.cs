/*
 * @lc app=leetcode.cn id=143 lang=csharp
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (63.88%)
 * Likes:    931
 * Dislikes: 0
 * Total Accepted:    185.1K
 * Total Submissions: 289.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * 请将其重新排列后变为：
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
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
public class Solution {
    // 10 41; 81 45 84 41.8;
    public void ReorderList(ListNode head) {
        ListNode slow = head, fast = head.next;
        while(fast != null){
            fast = fast.next;
            if(fast == null){
                break;
            }
            fast = fast.next;
            slow = slow.next;
        }
        // Console.WriteLine($"{slow.val}");
        
        ListNode p = slow.next;
        var stk = new Stack<ListNode>();
        while(p != null){
            stk.Push(p);
            p = p.next;
        }
        slow.next = null;   // 暂时断开
        p = head;
        ListNode q;
        while(stk.Count > 0){
            var node = stk.Pop();
            q = p.next;
            p.next = node;
            node.next = q;
            p = q;
        }
        if(p != slow){
            slow.next.next = null;
        }
    }
    // 看错题目，做成归并
    public void ReorderList9(ListNode head) {
        // Console.WriteLine($"{head.val}");
        ListNode slow = head, fast = head.next;
        while(fast != null){
            fast = fast.next;
            if(fast == null){
                break;
            }
            fast = fast.next;
            slow = slow.next;
        }
        Console.WriteLine($"{slow.val}");
        
        ListNode p = head, q = slow.next, pp, qq;
        while(q != null){
            pp = p.next;
            p.next = q;
            qq = q.next;
            q.next = pp;
            p = pp;
            q = qq;
        }
        if(p == slow){
            p.next = null;
        }else{
            slow.next.next = null;
        }
    }
}
// @lc code=end
/*
[1,2,3,4]\n
[1,2,3,4,5]
*/
