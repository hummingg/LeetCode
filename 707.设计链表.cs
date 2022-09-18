/*
 * @lc app=leetcode.cn id=707 lang=csharp
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (33.76%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    124.8K
 * Total Submissions: 369.6K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 
 * 在链表类中实现这些功能：
 * 
 * 
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 * 
 * 
 */

// @lc code=start

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
        this.val = val;
        this.next = next;
    }
}
public class MyLinkedList {
    // 13 30 152 60.7; 74 58 128 60.5;
    int size = 0;
    ListNode head = null;
    public MyLinkedList() {

    }
    
    public int Get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        ListNode p = head;
        int i = 0;
        while(p != null && i < index){
            p = p.next;
            ++i;
        }
        return p.val;
    }
    
    public void AddAtHead(int val) {
        // Test();
        var q = new ListNode(val);
        if(head == null){
            head = q;
        }else{
            q.next = head;
            head = q;   // bug
        }
        ++size;
    }
    
    public void AddAtTail(int val) {
        // Test();
        var q = new ListNode(val);
        if(head == null){
            head = q;
        }else{
            ListNode p = head;
            while(p.next != null){
                p = p.next;
            }
            p.next = q;
        }
        ++size;
    }
    
    // 在链表中的第 index 个节点 之前 添加值为 val  的节点，成为新的 index
    public void AddAtIndex(int index, int val) {
        // Test();
        if(index > size){
            return;
        }else if(index == size){
            AddAtTail(val);
        }else if(index <= 0){
            AddAtHead(val);
        }else{
            ListNode p = head;
            int i = 0;
            while(p != null && i < index-1){
                p = p.next;
                ++i;
            }
            var r = p.next;
            var q = new ListNode(val);
            p.next = q;
            q.next = r;
            ++size;
        }
    }
    
    public void DeleteAtIndex(int index) {
        // Test();
        if(index < 0 || index >= size){
            return;
        }
        if(index == 0){
            head = head.next;
        }else{
            ListNode p = head;
            int i = 0;
            while(p != null && i < index-1){
                p = p.next;
                ++i;
            }
            p.next = p.next.next;
        }
        --size;
    }

    public void Test(){
        ListNode p = head;
        while(p != null){
            Console.Write($"{p.val} -> ");
            p = p.next;
        }
        Console.WriteLine();
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
// @lc code=end
/*
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]\n
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
*/
