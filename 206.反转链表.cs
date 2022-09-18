/*
 * @lc app=leetcode.cn id=206 lang=csharp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.95%)
 * Likes:    2542
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
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
    // 迭代
    // 28: 89.54%(76ms) 53.14%(38.1MB);
    public ListNode ReverseList(ListNode head) {
        if(head == null){
            return null;
        }
        var p = head;
        var q = p.next;
        var h = p;  // 原地
        h.next = null;
        p = q;
        while(p != null){
            q = p.next;
            p.next = h;
            h = p;
            p = q;
        }
        return h;
    }

    // 递归
    // 28: 44.03%(84ms) 37.52%(38.2MB);
    public ListNode newhead, newtail;
    public ListNode ReverseList1(ListNode head) {
        var t = RecurReverseList(head);
        if(t != null){
            t.next = null;
        }
        return newhead;
    }
    // 返回部分链表的尾结点
    public ListNode RecurReverseList(ListNode head) {
        if(newtail != null){
            newtail = head;
        }
        if(head == null){
            return null;
        }
        if(head.next == null){
            newhead = head;
            return head;
        }
        var h = head;
        var newh = RecurReverseList(head.next);
        newh.next = h;
        return h;
    }
}
// @lc code=end

