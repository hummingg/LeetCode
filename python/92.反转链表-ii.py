#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#
# https://leetcode.cn/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (55.55%)
# Likes:    1389
# Dislikes: 0
# Total Accepted:    336.4K
# Total Submissions: 605.3K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
# 反转后的链表 。
# 
# 
# 示例 1：
# 
# 
# 输入：head = [1,2,3,4,5], left = 2, right = 4
# 输出：[1,4,3,2,5]
# 
# 
# 示例 2：
# 
# 
# 输入：head = [5], left = 1, right = 1
# 输出：[5]
# 
# 
# 
# 
# 提示：
# 
# 
# 链表中节点数目为 n
# 1 
# -500 
# 1 
# 
# 
# 
# 
# 进阶： 你可以使用一趟扫描完成反转吗？
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    # 44: 97.95%(28ms) 54.4%(15.1MB);
    # 进阶：头插法
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        '''
            将链表分为3段子链表
        '''
        
        dummyhead = ListNode()  # 带头节点
        dummyhead.next = head
        first_tail = dummyhead
        
        p = dummyhead
        cnt = 0
        while cnt < left-1:
            p = p.next
            cnt += 1    # p是第cnt个结点
            first_tail.next = p
            first_tail = p
        # cnt = left-1，p是第一段的尾结点
        # print(first_tail.val)
        
        p = p.next
        cnt += 1    # p是第cnt个结点
        second_head = p
        second_tail = p
        third_head = p.next
        # print(second_head.val)
        while cnt < right:
            p = third_head
            cnt += 1
            third_head = p.next
            p.next = second_head    # 头插法
            # print(p.val)
            second_head = p
        
        first_tail.next = second_head
        second_tail.next = third_head
        return dummyhead.next
        
# @lc code=end
'''
[1,2,3,4,5]\n2\n4\n
[1,2,3,4,5]\n1\n5\n
[1,2,3,4,5]\n2\n2\n
[5]\n1\n1\n
'''
