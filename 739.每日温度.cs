using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=739 lang=csharp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.16%)
 * Likes:    1170
 * Dislikes: 0
 * Total Accepted:    304.1K
 * Total Submissions: 439.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i
 * 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 73 38; 28 24 320 61.4;
    // 单调非严格递减栈
    public int[] DailyTemperatures(int[] temperatures) {
        var stk = new Stack<int>();
        stk.Push(0);
        int size = temperatures.Length;
        var ret = new int[size];    // 默认为 0
        for(var i = 1; i < size; i++){
            while(stk.Count > 0 && temperatures[stk.Peek()] < temperatures[i]){
                ret[stk.Peek()] = i - stk.Peek();
                stk.Pop();
            }
            stk.Push(i);
        }
        return ret;
    }
    
    // 30 <= temperatures[i] <= 100
    // 思路错误
    public int[] DailyTemperatures9(int[] temperatures) {
        int size = temperatures.Length;
        var dic = new SortedDictionary<int, List<int>>();
        for(var i = 0; i < size; i++){
            if(dic.ContainsKey(temperatures[i])){
                dic[temperatures[i]].Add(i);
            }else{
                dic.Add(temperatures[i], new List<int>(){i});
            }
        }
        var ret = new int[size];    // 默认为 0
        for(var i = 0; i < size; i++){
            var found = false;
            foreach(var kvp in dic){
                if(found){
                    break;
                }
                if(kvp.Key > temperatures[i]){
                    foreach(var idx in kvp.Value){
                        if(idx > i){
                            ret[i] = idx - i;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
}
// @lc code=end
/*
[73,74,75,71,69,72,76,73]\n
[30,40,50,60]\n
[30,60,90]
*/
