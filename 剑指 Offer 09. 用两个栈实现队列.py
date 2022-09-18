'''
剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 
示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
通过次数472,725提交次数668,547


执行用时：
352 ms
, 在所有 Python3 提交中击败了
52.24%
的用户
内存消耗：
19.1 MB
, 在所有 Python3 提交中击败了
37.38%
的用户
通过测试用例：
55 / 55

'''

class CQueue:

    def __init__(self):
        self.head = []  # 出队栈，用来出队，出栈顺序同队列出队
        self.tail = []  # 入队栈，用来入队

    def appendTail(self, value: int) -> None:
        self.tail.append(value) # 入栈

    def deleteHead(self) -> int:
        if len(self.head) > 0:  # 栈长
            return self.head.pop(-1)    # 出栈
        while len(self.tail) > 0:
            self.head.append(self.tail.pop(-1))
        return self.head.pop(-1) if len(self.head) > 0 else -1