using System.Security.Cryptography;
using System;
/*
 * @lc app=leetcode.cn id=445 lang=csharp
 *
 * [445] 两数相加 II
 *
 * https://leetcode.cn/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (59.76%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    103.3K
 * Total Submissions: 172.8K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入：l1 = [7,2,4,3], l2 = [5,6,4]
 * 输出：[7,8,0,7]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[8,0,7]
 * 
 * 
 * 示例3：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 100]
 * 0 <= node.val <= 9
 * 输入数据保证链表代表的数字无前导 0
 * 
 * 
 * 
 * 
 * 进阶：如果输入链表不能翻转该如何解决？
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
    // 79 71 88 48.4; 52 89 92 48.1;
    // 进阶：递归
    private ListNode newHead;
    private int carry = 0;
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = 0, len2 = 0;
        ListNode p = l1;
        while(p != null){
            ++len1;
            p = p.next;
        }
        p = l2;
        while(p != null){
            ++len2;
            p = p.next;
        }
        int diff = Math.Abs(len1-len2);
        ListNode shrt = l1, lng = l2;
        if(diff > 0){
            if(len1 > len2){
                shrt = l2;
                lng = l1;
            }
            for(int i = 0; i < diff; ++i){
                p = new ListNode(0, shrt);
                shrt = p;
            }
        }
        newHead = Recur(lng, shrt);
        // Console.WriteLine($"Text");
        
        if(carry > 0){
            p = new ListNode(carry, newHead);
            newHead = p;
        }
        return newHead;
    }

    private ListNode Recur(ListNode h1, ListNode h2){
        if(h1 == null || h2 == null){
            return null;
        }
        var p = Recur(h1.next, h2.next);
        if(newHead == null && p != null){
            p.next = null;
        }
        newHead = p;
        int partSum = h1.val + h2.val + carry;
        // Console.WriteLine($"{partSum}");
        carry = partSum / 10;
        return new ListNode(partSum % 10, newHead);
    }
}
// @lc code=end
/*
[7,2,4,3]\n[5,6,4]\n
[2,4,3]\n[5,6,4]\n
[0]\n[0]
*/
