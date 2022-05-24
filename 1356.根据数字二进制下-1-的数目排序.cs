using System;
/*
 * @lc app=leetcode.cn id=1356 lang=csharp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 *
 * https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/description/
 *
 * algorithms
 * Easy (73.05%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    50.7K
 * Total Submissions: 69.4K
 * Testcase Example:  '[0,1,2,3,4,5,6,7,8]'
 *
 * 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
 * 
 * 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
 * 
 * 请你返回排序后的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [0,1,2,3,4,5,6,7,8]
 * 输出：[0,1,2,4,8,3,5,6,7]
 * 解释：[0] 是唯一一个有 0 个 1 的数。
 * [1,2,4,8] 都有 1 个 1 。
 * [3,5,6] 有 2 个 1 。
 * [7] 有 3 个 1 。
 * 按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
 * 输出：[1,2,4,8,16,32,64,128,256,512,1024]
 * 解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [10000,10000]
 * 输出：[10000,10000]
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [2,3,5,7,11,13,17,19]
 * 输出：[2,3,5,17,7,11,13,19]
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [10,100,1000,10000]
 * 输出：[10,100,10000,1000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^4
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 64 56;
    public int[] SortByBits(int[] arr) {
        Array.Sort(arr);
        var dict = new SortedDictionary<int, List<int>>();
        for(int i = 0; i < arr.Length; ++i){
            int key = PopCount(arr[i]);
            if(dict.ContainsKey(key)){
                dict[key].Add(arr[i]);
            }else{
                dict.Add(key, new List<int>(){arr[i]});
            }
        }
        var ret = new int[arr.Length];
        int idx = 0;
        foreach(var kvp in dict){
            foreach(var num in kvp.Value){
                ret[idx++] = num;
            }
        }
        return ret;
    }

    // 二进制中1的个数
    // 101&100 100&011 0
    public int PopCount(int n) {
        int counter = 0;
        while(n > 0){
            counter++;
            n = n & (n-1);
        }
        return counter;
    }
}
// @lc code=end

