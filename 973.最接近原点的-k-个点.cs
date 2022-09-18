using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=973 lang=csharp
 *
 * [973] 最接近原点的 K 个点
 *
 * https://leetcode.cn/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (64.80%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    81.4K
 * Total Submissions: 125.6K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * 给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0)
 * 最近的 k 个点。
 * 
 * 这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)^2 + (y1 - y2)^2 ）。
 * 
 * 你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：points = [[1,3],[-2,2]], k = 1
 * 输出：[[-2,2]]
 * 解释： 
 * (1, 3) 和原点之间的距离为 sqrt(10)，
 * (-2, 2) 和原点之间的距离为 sqrt(8)，
 * 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
 * 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[3,3],[5,-1],[-2,4]], k = 2
 * 输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= points.length <= 10^4
 * -10^4 < xi, yi < 10^4
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 57 51; 38 93 316 66.5;
    // 败者树？二分查找
    public int[][] KClosest(int[][] points, int k) {
        var size = points.Length;
        var lst = new List<KeyValuePair<int,int>>();
        for(int i = 0; i < k; ++i){
            lst.Add(new KeyValuePair<int, int>(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
        }
        lst.Sort((p1, p2) => p1.Key.CompareTo(p2.Key));
        // foreach(var kvp in lst){
        //     Console.WriteLine($"{kvp.Key}");
        // }
        for(int i = k; i < size; ++i){
            var target = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(target < lst[k-1].Key){
                lst.Insert(BinarySearch(lst, target), new KeyValuePair<int, int>(target, i));
                lst.RemoveAt(lst.Count-1);
            }
        }
        var ret = new int[k][];
        for(int i = 0; i < k; ++i){
            ret[i] = points[lst[i].Value];
        }
        return ret;
    }

    // 找第一个更大的
    public int BinarySearch(IList<KeyValuePair<int,int>> lst, int target){
        int low = 0, high = lst.Count - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(lst[mid].Key <= target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return lst[low].Key > target ? low : low + 1;
    }
}
// @lc code=end
/*
[[1,3],[-2,2]]\n1\n
[[3,3],[5,-1],[-2,4]]\n2\n
[[5,-1],[-2,4],[3,3]]\n2
*/
