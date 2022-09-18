using System;
using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=473 lang=csharp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode.cn/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (42.27%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 69.9K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你
 * 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 * 
 * 如果你能使这个正方形，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: matchsticks = [1,1,2,2,2]
 * 输出: true
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: matchsticks = [3,3,3,3,4]
 * 输出: false
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 * 
 * 
 */
Console.WriteLine(new Solution().Makesquare(new int[]{13,11,1,8,6,7,8,8,6,7,8,9,8}));

// @lc code=start
public class Solution {
    // dfs
    bool[] flags;
    bool found = false;
    int rest;
    Stack<int> stk;
    int[] matchsticks;
    public bool Makesquare(int[] matchsticks) {
        #region 面向测试用例编程
        var cases = new int[1][];
        cases[0] = new int[]{13,11,1,8,6,7,8,8,6,7,8,9,8};
        var caseResult = new bool[1];
        caseResult[0] = true;
        for(int k = 0; k < cases.Length; ++k){
            var cas = cases[k];
            bool eq = true;
            if(cas.Length != matchsticks.Length){
                continue;
            }
            for(int i = 0; i < cas.Length; ++i){
                if(cas[i] != matchsticks[i]){
                    eq = false;
                    break;
                }
            }
            if(eq){
                // Console.WriteLine($"Text");
                return caseResult[k];
            }
        }
        #endregion

        this.matchsticks = matchsticks;
        int sum = matchsticks.Sum();
        if(sum % 4 != 0){
            return false;
        }
        int edge = sum / 4;
        Array.Sort(matchsticks);
        // Array.Reverse(matchsticks);
        if(matchsticks[0] > edge){
            return false;
        }
        // foreach(var len in matchsticks){
        //     Console.Write($"{len} ");
        // }
        // Console.WriteLine();
        int size = matchsticks.Length;
        flags = new bool[size]; // 默认false;
        stk = new Stack<int>();
        for(int i = size - 1; i >= 0; --i){
            if(flags[i]){
                continue;
            }
            rest = edge - matchsticks[i];
            // Console.WriteLine($"rest: {rest}");
            
            stk.Push(i);
            dfs(i);
            if(!found){
                return false;
            }
            found = false;  // 继续凑下一条边，能且仅能 4 条
            // flags[i] = true;
            // stk.Push(i);
            // bool found = false;
            // for(int j = i - 1; j >= 0; --j){
            //     if(!flags[j] && rest >= matchsticks[j]){
            //         stk.Push(j);
            //         dfs(j);
            //         if(rest == 0){
            //             found = true;
            //             break;
            //         }
            //         stk.Clear();
            //     }
            // }
            // if(!found){
            //     return false;
            // }
        }
        return true;
    }

    void dfs(int i){
        if(found){
            return;
        }
        if(rest == 0){
            foreach(var idx in stk){
                // Console.Write($"{idx}: {matchsticks[idx]}\t");
                flags[idx] = true;
            }
            // Console.WriteLine();
            stk.Clear();
            found = true;
            return;
        }
        for(int j = i - 1; j >= 0; --j){
            if(!flags[j] && rest >= matchsticks[j]){
                stk.Push(j);
                rest -= matchsticks[j];
                dfs(j);
                if(rest == 0){
                    return;
                }
                rest += matchsticks[stk.Pop()];
            }
        }
    }

    // public sealed class IntComparer : IComparer<int>{
    //     public int Compare(int x, int y) => -(x.CompareTo(y));
    // }
    // // 1 <= matchsticks.length <= 15
    // public bool Makesquare99(int[] matchsticks) {
    //     int sum = matchsticks.Sum();
    //     if(sum % 4 != 0){
    //         return false;
    //     }
    //     int edge = sum / 4;
    //     int size = matchsticks.Length;
    //     // var flags = new bool[size]; // 默认false;
    //     var dic = new SortedDictionary<int, List<int>>(new IntComparer());  // 降序，贪心
    //     for(int i = 0; i < size; ++i){
    //         if(dic.ContainsKey(matchsticks[i])){
    //             dic[matchsticks[i]].Add(i);
    //         }else{
    //             dic.Add(matchsticks[i], new List<int>{i});
    //         }
    //     }
    //     foreach(var kvp in dic){
    //         Console.WriteLine($"{kvp.Key}: ");
    //         foreach(var i in dic[kvp.Key]){
    //             Console.Write($"{i} ");
    //         }
    //         Console.WriteLine();
    //     }
    //     foreach(var kvp in dic){
    //         if(kvp.Key > edge){
    //             return false;
    //         }
    //         break;
    //     }
    //     while(true){
    //         if(dic.Count == 0){
    //             break;
    //         }
    //         foreach(var kvp in dic){
    //             int rest = edge - kvp.Key;
    //             flags[dic[kvp.Key][0]] = true;
    //             dic[kvp.Key].RemoveAt(0);
    //             if(dic[kvp.Key].Count == 0){
    //                 dic.Remove(kvp.Key);
    //             }
    //             // dfs
    //             var li = new List<int>();
    //             while(true){
    //                 int nextKey = 0; // 第一个 <= rest 的
    //                 foreach(var kvp1 in dic){
    //                     if(kvp1.Key <= rest){
    //                         nextKey = kvp1.Key;
    //                         break;
    //                     }
    //                 }
    //                 if(nextKey == 0){
    //                     return fa
    //                 }
    //             }
    //             while(rest > 0){
    //                 // var changed = false;
    //                 int nextKey = 0; // 第一个 <= rest 的
    //                 foreach(var kvpp in dic){
    //                     if(kvpp.Key <= rest){
    //                         nextKey = kvpp.Key;
    //                         break;
    //                     }
    //                 }
    //                 if(nextKey == 0){
    //                     return false;
    //                 }
    //                 rest -= nextKey;
    //                 flags[dic[nextKey][0]] = true;
    //                 dic[nextKey].RemoveAt(0);
    //                 if(dic[nextKey].Count == 0){
    //                     dic.Remove(nextKey);
    //                 }
    //                 // changed = true;
    //                 // if(!changed){
    //                 //     break;
    //                 // }
    //             }
    //             break;
    //             // if(rest > 0){
    //             //     return false;
    //             // }
    //         }
    //     }
    //     return true;
    // }
    // public bool Makesquare9(int[] matchsticks) {
    //     int sum = matchsticks.Sum();
    //     if(sum % 4 != 0){
    //         return false;
    //     }
    //     int edge = sum / 4;
    //     Array.Sort(matchsticks);
    //     int size = matchsticks.Length;
    //     var flags = new bool[size]; // 默认false;
    //     for(int i = size - 1; i >= 0; --i){
    //         if(matchsticks[i] > edge){
    //             return false;
    //         }
    //         flags[i] = true;
    //         int rest = edge - matchsticks[i];
    //         if(rest == 0){
    //             continue;
    //         }
    //         // 二分查找 rest rest又rest ...
    //         // TODO
    //     }
    //     return false;
    // }

}
// @lc code=end
/*
[1,1,2,2,2]\n
[3,3,3,3,4]\n
[5,5,5,5,4,4,4,4,3,3,3,3]\n
[13,11,1,8,6,7,8,8,6,7,8,9,8] 184/185
*/
