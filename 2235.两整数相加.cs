using System.Collections;
// using System.Collections.ObjectModel;
// using System.Collections.Generic;
// using System.Collections;
/*
 * @lc app=leetcode.cn id=2235 lang=csharp
 *
 * [2235] 两整数相加
 *
 * https://leetcode.cn/problems/add-two-integers/description/
 *
 * algorithms
 * Easy (89.09%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 4.1K
 * Testcase Example:  '12\n5'
 *
 * 给你两个整数 num1 和 num2，返回这两个整数的和。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = 12, num2 = 5
 * 输出：17
 * 解释：num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = -10, num2 = 4
 * 输出：-6
 * 解释：num1 + num2 = -6 ，因此返回 -6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100 <= num1, num2 <= 100
 * 
 * 
 */

// using Dictionary=System.Collections.Generic.Dictionary;

int num1 = -10, num2 = 4;
Console.WriteLine(new Solution().Sum(num1, num2));

// @lc code=start
public class Solution {
    public int Sum(int num1, int num2) {
        // System.Collections.Generic.Dictionary<string, int> dic = new System.Collections.Generic.Dictionary<string, int>();
        var dic = new Dictionary<string, int>();
        dic.Add("one", 1);
        foreach (var item in dic)
        {
            Console.WriteLine(item);
        }
        
        // System.Collections.ArrayList al = new System.Collections.ArrayList();
        // var al = new ArrayList();
        // al.Add(45);
        // al.Add(45.0);
        // al.Add('a');
        // foreach (var item in al)
        // {
        //     Console.WriteLine(item);
        // }

        // Array(int[n]) -> ArrayList -> List<T>(C++.Vector) -> LinkedList<T>(双链表,LinkedListNode<T>) -> SortedList<T>
        // HashSet<T>(SortedSet<T>) -> Hashtable -> Dictionary<TK,TV>(KeyValuePair<TK,TV>) -> SortedDictionary<TK,TV>

        // System.Collections.Generic.IList<int> l = new System.Collections.Generic.List<int>();
        var l = new List<int>();
        l.Add(111);
        foreach (var item in l)
        {
            Console.WriteLine(item);
        }

        return num1 + num2;
    }
}
// @lc code=end
