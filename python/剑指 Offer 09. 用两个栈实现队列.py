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
        


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()