using System;
using System.Runtime.InteropServices;
/*
 * @lc app=leetcode.cn id=497 lang=csharp
 *
 * [497] 非重叠矩形中的随机点
 *
 * https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (40.79%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 10.7K
 * Testcase Example:  '["Solution","pick","pick","pick","pick","pick"]\n' +
  '[[[[-2,-2,1,1],[2,2,4,6]]],[],[],[],[],[]]'
 *
 * 给定一个由非重叠的轴对齐矩形的数组 rects ，其中 rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i
 * 个矩形的左下角点，(xi, yi) 是第 i
 * 个矩形的右上角角点。设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。
 * 
 * 在一个给定的矩形覆盖的空间内任何整数点都有可能被返回。
 * 
 * 请注意 ，整数点是具有整数坐标的点。
 * 
 * 实现 Solution 类:
 * 
 * 
 * Solution(int[][] rects) 用给定的矩形数组 rects 初始化对象。
 * int[] pick() 返回一个随机的整数点 [u, v] 在给定的矩形所覆盖的空间内。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: 
 * ["Solution","pick","pick","pick","pick","pick"]
 * [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
 * 输出: 
 * [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]
 * 
 * 解释：
 * Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
 * solution.pick(); // 返回 [1, -2]
 * solution.pick(); // 返回 [1, -1]
 * solution.pick(); // 返回 [-1, -2]
 * solution.pick(); // 返回 [-2, -2]
 * solution.pick(); // 返回 [0, 0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rects.length <= 100
 * rects[i].length == 4
 * -10^9 <= ai < xi <= 10^9
 * -10^9 <= bi < yi <= 10^9
 * xi - ai <= 2000
 * yi - bi <= 2000
 * 所有的矩形不重叠。
 * pick 最多被调用 10^4 次。
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 75 50;
    int[][] rects;
    int[] preSum;
    int size;
    Random rand;
    public Solution(int[][] rects) {
        rand = new Random();
        this.rects = rects;
        size = rects.Length;
        preSum = new int[size+1];
        for(int i = 0; i < size; ++i){
            var rect = rects[i];
            preSum[i+1] = preSum[i] + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }
        // foreach(var cnt in preSum){
        //     Console.Write($"{cnt} ");
        // }
        // Console.WriteLine();
    }
    
    public int[] Pick() {
        int pos = rand.Next() % preSum[size] + 1;   // 第pos个点，从1开始计数
        int rectidx = BinarySearch(pos) - 1;    // 下一个矩形的索引
        int pointidx = pos - preSum[rectidx]; // 用上矩形 rectidx-1 后还差几个点
        int row = rects[rectidx][3] - rects[rectidx][1] + 1;
        // Console.WriteLine($"{pos} {rectidx} {pointidx} {row}");
        if(pointidx == 0){
            return new int[2]{rects[rectidx-1][2], rects[rectidx-1][3]};
        }
        return new int[2]{rects[rectidx][0] + (pointidx-1) / row, rects[rectidx][1]+ (pointidx-1) % row};

    }

    public int BinarySearch(int target){
        int low = 1, high = size;
        while(low < high){
            int mid = (low + high) / 2;
            if(preSum[mid] < target){
                low = mid + 1;
            }else if(preSum[mid] == target){
                return mid;
            }else{
                high = mid - 1;
            }
        }
        // low == high
        if(preSum[low] < target){
            return low + 1;
        }
        return low;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.Pick();
 */
// @lc code=end

