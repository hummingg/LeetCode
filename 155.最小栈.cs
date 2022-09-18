using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=155 lang=csharp
 *
 * [155] 最小栈
 *
 * https://leetcode.cn/problems/min-stack/description/
 *
 * algorithms
 * Easy (58.18%)
 * Likes:    1322
 * Dislikes: 0
 * Total Accepted:    387.4K
 * Total Submissions: 665.4K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 实现 MinStack 类:
 * 
 * 
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * pop、top 和 getMin 操作总是在 非空栈 上调用
 * push, pop, top, and getMin最多被调用 3 * 10^4 次
 * 
 * 
 */

// @lc code=start
public class MinStack {
    // 56 83; 31 28 124 49.6;
    // 在常数时间内检索到最小元素
    Stack<int> stk;
    // Stack<int[]> minStk;
    Stack<KeyValuePair<int,int>> minStk;
    public MinStack() {
        stk = new Stack<int>();
        // minStk = new Stack<int[2]>();
        minStk = new Stack<KeyValuePair<int,int>>();
    }
    
    public void Push(int val) {
        stk.Push(val);
        if(minStk.Count > 0){
            if(minStk.Peek().Key == val){
                // minStk.Peek().Value += 1;    // kvp cann't be assigned
                var kvp = minStk.Pop();
                // pk.Value++;  // kvp cann't be assigned
                minStk.Push(new KeyValuePair<int, int>(kvp.Key, kvp.Value+1));
            }else if(minStk.Peek().Key > val){
                minStk.Push(new KeyValuePair<int, int>(val, 1));
            }
        }else{
            minStk.Push(new KeyValuePair<int, int>(val, 1));
        }
    }
    
    public void Pop() {
        var val = stk.Pop();
        var kvp = minStk.Peek();
        if(val == kvp.Key){
            minStk.Pop();
            if(kvp.Value > 1){
                minStk.Push(new KeyValuePair<int, int>(kvp.Key, kvp.Value-1));
            }
        }
    }
    
    public int Top() {
        return stk.Peek();
    }
    
    public int GetMin() {
        return minStk.Peek().Key;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */
// @lc code=end
/*
["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
["MinStack","push","push","push","getMin","pop","getMin"]\n[[],[0],[1],[0],[],[],[]]
*/
