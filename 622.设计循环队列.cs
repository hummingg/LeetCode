/*
 * @lc app=leetcode.cn id=622 lang=csharp
 *
 * [622] 设计循环队列
 *
 * https://leetcode.cn/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    83.9K
 * Total Submissions: 188.8K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于
 * FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 * 
 * 
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 * 
 * 你的实现应该支持如下操作：
 * 
 * 
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
 * circularQueue.enQueue(1);  // 返回 true
 * circularQueue.enQueue(2);  // 返回 true
 * circularQueue.enQueue(3);  // 返回 true
 * circularQueue.enQueue(4);  // 返回 false，队列已满
 * circularQueue.Rear();  // 返回 3
 * circularQueue.isFull();  // 返回 true
 * circularQueue.deQueue();  // 返回 true
 * circularQueue.enQueue(4);  // 返回 true
 * circularQueue.Rear();  // 返回 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有的值都在 0 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 * 
 * 
 */

// @lc code=start
public class MyCircularQueue {
    // 96 78 108 51.4; 47 64 124 51.5;
    int[] arr;
    int front, rear;
    int size;
    public MyCircularQueue(int k) {
        arr = new int[k+1]; // rear指向下一个Enque的位置，所以需要多一个空间
        this.size = k+1;
        // front = 0;
        // rear = 0;
    }
    
    public bool EnQueue(int value) {
        if(IsFull()){
            return false;
        }
        arr[rear] = value;
        rear = (rear+1) % size;
        return true;
    }
    
    public bool DeQueue() {
        if(IsEmpty()){
            return false;
        }
        front = (front+1) % size;
        return true;
    }
    
    public int Front() {
        if(IsEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    public int Rear() {
        if(IsEmpty()){
            return -1;
        }
        return arr[(rear-1+size) % size];
    }
    
    public bool IsEmpty() {
        return front == rear;
    }
    
    public bool IsFull() {
        return front == (rear+1) % size;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.EnQueue(value);
 * bool param_2 = obj.DeQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.IsEmpty();
 * bool param_6 = obj.IsFull();
 */
// @lc code=end

