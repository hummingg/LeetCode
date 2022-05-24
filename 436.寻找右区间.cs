using System;
/*
 * @lc app=leetcode.cn id=436 lang=csharp
 *
 * [436] 寻找右区间
 *
 * https://leetcode.cn/problems/find-right-interval/description/
 *
 * algorithms
 * Medium (49.55%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 48.4K
 * Testcase Example:  '[[1,2]]'
 *
 * 给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
 * 
 * 区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。
 * 
 * 返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,2]]
 * 输出：[-1]
 * 解释：集合中只有一个区间，所以输出-1。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[3,4],[2,3],[1,2]]
 * 输出：[-1,0,1]
 * 解释：对于 [3,4] ，没有满足条件的“右侧”区间。
 * 对于 [2,3] ，区间[3,4]具有最小的“右”起点;
 * 对于 [1,2] ，区间[2,3]具有最小的“右”起点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：intervals = [[1,4],[2,3],[3,4]]
 * 输出：[-1,2,-1]
 * 解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
 * 对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 2 * 10^4
 * intervals[i].length == 2
 * -10^6 <= starti <= endi <= 10^6
 * 每个间隔的起点都 不相同
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 100 13;
    public int[] FindRightInterval(int[][] intervals) {
        int size = intervals.Length;
        var startIndex = new List<Tuple<int,int>>();
        for(int i = 0; i < size; ++i){
            startIndex.Add(new Tuple<int,int>(intervals[i][0], i));
        }
        startIndex.Sort((t1, t2) =>  t1.Item1 < t2.Item1 ? -1 : 1 );
        // foreach(var t in startIndex){
        //     Console.Write(t.Item1 + " ");
        //     Console.WriteLine(t.Item2);
        // }
        int[] ret = new int[size];
        for(int i = 0; i < size; ++i){
            ret[i] = -1;
            int end = intervals[i][1];
            int low = 0, high = size - 1 ;
            while(low < high){
                int mid = (low + high) / 2; // 二分查找
                if(startIndex[mid].Item1 < end){
                    low = mid + 1;
                }else if(startIndex[mid].Item1 > end){
                    high = mid - 1;
                }else{
                    ret[i] = startIndex[mid].Item2;
                    break;
                }
            }
            if(ret[i] == -1){   // low == high
                if(startIndex[low].Item1 < end){
                    if(low + 1 < size){
                        ret[i] = startIndex[low + 1].Item2;
                    }
                }else{
                    ret[i] = startIndex[low].Item2;
                }
            }
        }
        return ret;
    }
}
// @lc code=end
/*
[[1,2]]\n
[[3,4],[2,3],[1,2]]\n
[[1,4],[2,3],[3,4]]\n
[[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]
*/
