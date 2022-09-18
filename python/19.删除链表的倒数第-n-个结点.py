#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#
# https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
#
# algorithms
# Medium (44.56%)
# Likes:    2204
# Dislikes: 0
# Total Accepted:    914.3K
# Total Submissions: 2.1M
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：head = [1,2,3,4,5], n = 2
# 输出：[1,2,3,5]
# 
# 
# 示例 2：
# 
# 
# 输入：head = [1], n = 1
# 输出：[]
# 
# 
# 示例 3：
# 
# 
# 输入：head = [1,2], n = 1
# 输出：[1]
# 
# 
# 
# 
# 提示：
# 
# 
# 链表中结点的数目为 sz
# 1 <= sz <= 30
# 0 <= Node.val <= 100
# 1 <= n <= sz
# 
# 
# 
# 
# 进阶：你能尝试使用一趟扫描实现吗？
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 208: 54.58%(40ms) 53.5%(14.9MB);
    def __init__(self):
        self.n = 0
        self.flag = False
    
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        self.n = n
        self.recur(head)
        if not self.flag:   # 倒数第n个是head
            return head.next
        return head
    
    # 递归
    def recur(self, head: Optional[ListNode]) -> int:
        if self.flag:
            return  # 尽快结束递归
        if not head:
            return 0    # 倒数第0个是None
        k = self.recur(head.next) # 倒数第k个是head.next，倒数第k+1个是head
        if self.flag:
            return  # 尽快结束递归，不做多余操作
        if k == self.n:   # 令被删除的倒数第self.n个是head.next，则k应等于self.n
            head.next = head.next.next
            self.flag = True
        return k+1  # 倒数第k+1个是head
# @lc code=end
'''
[1,2,3,4,5]\n2\n
[1]\n1\n
[1,2]\n1\n
'''
