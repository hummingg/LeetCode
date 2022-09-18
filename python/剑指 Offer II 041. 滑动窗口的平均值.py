# 剑指 Offer II 041. 滑动窗口的平均值
'''
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
 

示例：

输入：
inputs = ["MovingAverage", "next", "next", "next", "next"]
inputs = [[3], [1], [10], [3], [5]]
输出：
[null, 1.0, 5.5, 4.66667, 6.0]

解释：
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
 

提示：

1 <= size <= 1000
-105 <= val <= 105
最多调用 next 方法 104 次
 

注意：本题与主站 346 题相同： https://leetcode-cn.com/problems/moving-average-from-data-stream/
'''

class MovingAverage:
    # 11: 83.00%(64ms) 49.40%(18.2MB)
    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.preSum = 0
        self.size = size
        self.queue = []


    def next(self, val: int) -> float:
        if len(self.queue) == self.size:
            self.preSum -= self.queue[0]
            self.queue.pop(0)
        self.queue.append(val)
        self.preSum += val
        return self.preSum / len(self.queue)
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)