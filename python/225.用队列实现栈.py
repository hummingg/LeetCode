#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] 用队列实现栈
#
# https://leetcode.cn/problems/implement-stack-using-queues/description/
#
# algorithms
# Easy (67.50%)
# Likes:    562
# Dislikes: 0
# Total Accepted:    217.8K
# Total Submissions: 322.6K
# Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
#
# 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
# 
# 实现 MyStack 类：
# 
# 
# void push(int x) 将元素 x 压入栈顶。
# int pop() 移除并返回栈顶元素。
# int top() 返回栈顶元素。
# boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
# 
# 
# 
# 
# 注意：
# 
# 
# 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty
# 这些操作。
# 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
# 
# 
# 
# 
# 示例：
# 
# 
# 输入：
# ["MyStack", "push", "push", "top", "pop", "empty"]
# [[], [1], [2], [], [], []]
# 输出：
# [null, null, null, 2, 2, false]
# 
# 解释：
# MyStack myStack = new MyStack();
# myStack.push(1);
# myStack.push(2);
# myStack.top(); // 返回 2
# myStack.pop(); // 返回 2
# myStack.empty(); // 返回 False
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= x <= 9
# 最多调用100 次 push、pop、top 和 empty
# 每次调用 pop 和 top 都保证栈不为空
# 
# 
# 
# 
# 进阶：你能否仅用一个队列来实现栈。
# 
#

# @lc code=start
class MyStack:
    # 进阶
    # 17: 96.89%(28ms) 15.78%(15.2MB);
    def __init__(self):
        # 队头for deque是栈底, queue's tail for enque is top of stack
        self.queue = []

    def push(self, x: int) -> None:
        # self.queue.append(x)
        self.queue_push(x)

    def pop(self) -> int:
        # count = len(self.queue)
        # while count > 1:
        #     self.queue.append(self.queue.pop(0))  # push、pop
        #     count -= 1
        # return self.queue.pop(0)
        count = self.queue_size()
        while count > 1:
            self.queue_push(self.queue_pop())
            count -= 1
        return self.queue_pop()

    def top(self) -> int:
        # count = len(self.queue)
        # while count > 1:
        #     self.queue.append(self.queue.pop(0))  # push、pop
        #     count -= 1
        # ret = self.queue.pop(0)
        # self.queue.append(ret)
        # return ret
        count = self.queue_size()
        while count > 1:
            self.queue_push(self.queue_pop())
            count -= 1
        ret = self.queue_pop()
        self.queue_push(ret)
        return ret

    def empty(self) -> bool:
        # return len(self.queue) == 0
        return self.queue_isEmpty()
    
    
    # api of queue
    def queue_push(self, x: int):
        self.queue.append(x)
        
    def queue_pop(self) -> int:
        return self.queue.pop(0)
    
    def queue_peek(self) -> int:
        return self.queue[0]
    
    def queue_size(self):
        return len(self.queue)

    def queue_isEmpty(self):
        return self.queue_size() == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end

