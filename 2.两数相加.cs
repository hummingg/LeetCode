/*
 * @lc app=leetcode.cn id=2 lang=csharp
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.88%)
 * Likes:    8225
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
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
    // 86 52 84 48.2;
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1 = l1, p2 = l2;
        ListNode l3 = null, rear = l3;
        int partSum = 0, carry = 0;

        while(p1 != null && p2 != null){
            partSum = p1.val + p2.val + carry;
            carry = partSum / 10;

            if(l3 == null){
                l3 = new ListNode(partSum % 10);
                rear = l3;
            }else{
                rear.next = new ListNode(partSum % 10);
                rear = rear.next;
            }

            p1 = p1.next;
            p2 = p2.next;
        }
        
        ListNode p = p1 != null ? p1 : p2;
        while(p != null){
            partSum = carry + p.val;
            carry = partSum/10;
            rear.next = new ListNode(partSum%10);
            rear = rear.next;
            p = p.next;
        }
        if(carry != 0){
            rear.next = new ListNode(carry);
            rear = rear.next;
        }

        return l3;
    }
}
// @lc code=end

