/*
 * @lc app=leetcode.cn id=61 lang=csharp
 *
 * [61] 旋转链表
 *
 * https://leetcode.cn/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.67%)
 * Likes:    784
 * Dislikes: 0
 * Total Accepted:    255.7K
 * Total Submissions: 613.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    // 77 81 80 38.4; 92 55 76 38.5;
    public ListNode RotateRight(ListNode head, int k) {
        int len = 0;
        var p = head;
        var tail = head;
        while(p != null){
            tail = p;
            ++len;
            p = p.next;
        }
        if(len == 0 || k % len == 0){
            return head;
        }
        k = len - k % len;
        p = head;
        int i = 1;  // p=head 是第 1 个
        while(i < k){
            p = p.next;
            ++i;    // p 是第 i 个，从 1 开始编号
        }
        var newHead = p.next;
        p.next = null;
        tail.next = head;
        return newHead;
    }
}
// @lc code=end
/*
[1,2,3,4,5]\n2\n
[0,1,2]\n4\n
[0,1]\n0\n
[0,1]\n1\n
[0,1]\n2\n
[0,1]\n3\n
[0,1]\n4\n
[]\n0
*/
