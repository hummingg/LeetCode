using System;
/*
 * @lc app=leetcode.cn id=556 lang=csharp
 *
 * [556] 下一个更大元素 III
 *
 * https://leetcode.cn/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (33.52%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 62.6K
 * Testcase Example:  '12'
 *
 * 给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
 * 
 * 注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：21
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 21
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 96 33 16 26.5; 44 47 24 26.4;
    public int NextGreaterElement(int n) {
        var lst = new List<int>();  // 个位放在索引0
        while(n > 0){
            lst.Add(n % 10);
            n /= 10;
        }
        int size = lst.Count;
        int i = 0;
        for(; i < size - 1; ++i){
            if(lst[i] > lst[i+1]){
                break;
            }
        }
        if(i == size - 1){
            return -1;
        }

        var target = lst[i+1]; // 待替换为最小的较大值
        for(int j = 0; j < i+1; ++j){
            if(lst[j] > target){
                var tmp = lst[i+1];
                lst[i+1] = lst[j];
                lst[j] = tmp;
                break;
            }
        }
        lst.Reverse(0, i+1);    // 0->i 降序
        lst.Reverse();

        n = 0;
        foreach(var digit in lst){
            // Console.WriteLine($"{digit}");
            if((int.MaxValue - digit) / 10.0 < n){
                return -1;
            }
            n = n * 10 + digit;
        }
        return n;
    }

    // 81 30 20 26.7;
    public int NextGreaterElement1(int n) {
        var lst = new List<int>();  // 个位放在索引0
        while(n > 0){
            lst.Add(n % 10);
            n /= 10;
        }
        int size = lst.Count;
        int i = 0;
        for(; i < size - 1; ++i){
            if(lst[i] > lst[i+1]){
                break;
            }
        }
        if(i == size - 1){
            return -1;
        }

        var tmp = lst[i+1]; // 待替换为最小较大值

        lst.Sort(0, i+2, Comparer<int>.Default);    // 0->i+1 升序
        lst.Reverse(0, i+2);    // 0->i+1 降序
        for(int j = i + 1; j >= 0; --j){
            if(lst[j] > tmp){
                var tmp2 = lst[i+1];
                lst[i+1] = lst[j];
                lst[j] = tmp2;
                break;
            }
        }
        lst.Sort(0, i+1, Comparer<int>.Default);    // 0->i 升序
        lst.Reverse(0, i+1);    // 0->i 降序
        lst.Reverse();  // 个位放在末尾，低位又变成升序

        n = 0;
        foreach(var digit in lst){
            // Console.WriteLine($"{digit}");
            if((int.MaxValue - digit) / 10.0 < n){
                return -1;
            }
            n = n * 10 + digit;
        }
        return n;
    }
}
// @lc code=end
/*
12\n
21\n
51342\n
2147483476

2147483[4]7654 2147483[44[5]67] 2147483[54[4]67]
2147483[4]7[6]
2147483[6]7[4]
2147483[6][74]
2147483[6][47]

2147483647 √
2147483746 错
*/
