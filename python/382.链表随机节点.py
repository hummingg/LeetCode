#
# @lc app=leetcode.cn id=382 lang=python3
#
# [382] 链表随机节点
#
# https://leetcode.cn/problems/linked-list-random-node/description/
#
# algorithms
# Medium (72.57%)
# Likes:    309
# Dislikes: 0
# Total Accepted:    52.9K
# Total Submissions: 72.8K
# Testcase Example:  '["Solution","getRandom","getRandom","getRandom","getRandom","getRandom"]\n' +
#  '[[[1,2,3]],[],[],[],[],[]]'
#
# 给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。
# 
# 实现 Solution 类：
# 
# 
# Solution(ListNode head) 使用整数数组初始化对象。
# int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
# 
# 
# 
# 
# 示例：
# 
# 
# 输入
# ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
# [[[1, 2, 3]], [], [], [], [], []]
# 输出
# [null, 1, 3, 2, 2, 3]
# 
# 解释
# Solution solution = new Solution([1, 2, 3]);
# solution.getRandom(); // 返回 1
# solution.getRandom(); // 返回 3
# solution.getRandom(); // 返回 2
# solution.getRandom(); // 返回 2
# solution.getRandom(); // 返回 3
# // getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。
# 
# 
# 
# 提示：
# 
# 
# 链表中的节点数在范围 [1, 10^4] 内
# -10^4 <= Node.val <= 10^4
# 至多调用 getRandom 方法 10^4 次
# 
# 
# 
# 
# 进阶：
# 
# 
# 如果链表非常大且长度未知，该怎么处理？
# 你能否在不使用额外空间的情况下解决此问题？
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 8: 47.82%(132ms) 24.1%(17.8MB);
    # 进阶：不使用额外空间，洗牌算法
    def __init__(self, head: Optional[ListNode]):
        self.n = 0
        self.head = head
        p = head
        while p:
            self.n += 1
            p = p.next
        # print(p, head)

    def getRandom(self) -> int:
        # num = random.randint(1, 1)
        # print(num)
        cnt = self.n
        p = self.head
        while p:
            num = random.randint(0, cnt-1)
            if num == 0:
                return p.val
            else:
                p = p.next
                cnt -= 1
        return 99999


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
# @lc code=end

