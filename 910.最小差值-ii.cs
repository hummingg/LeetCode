using System;
/*
 * @lc app=leetcode.cn id=910 lang=csharp
 *
 * [910] 最小差值 II
 *
 * https://leetcode.cn/problems/smallest-range-ii/description/
 *
 * algorithms
 * Medium (33.91%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 26.2K
 * Testcase Example:  '[1]\n0'
 *
 * 给你一个整数数组 nums，和一个整数 k 。
 * 
 * 对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成  nums[i] + k 或 nums[i] - k 。
 * 
 * nums 的 分数 是 nums 中最大元素和最小元素的差值。
 * 
 * 在更改每个下标对应的值之后，返回 nums 的最小 分数 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1], k = 0
 * 输出：0
 * 解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,10], k = 2
 * 输出：6
 * 解释：将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,3,6], k = 3
 * 输出：3
 * 解释：将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^4
 * 0 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
public class Solution {
    public int SmallestRangeII(int[] nums, int k) {
        int size = nums.Length;
        if(size < 2){
            return 0;
        }
        // 排序去重
        Array.Sort(nums);
        int end = 0;
        for(int i = 1; i < size; ++i){
            if(nums[i] != nums[end]){
                nums[++end] = nums[i];
            }
        }
        int low = 0, high = end;
        int d = nums[high] - nums[low]; // 最大的 d
        int maxret = d;
        if(d <= k){ // 注意等号
            return maxret;
        }
        // int ret = Math.Abs(d-2*k);
        int mx = Math.Max(nums[low] + k, nums[high] - k);
        int mn = Math.Min(nums[low] + k, nums[high] - k);
        int low0, low1, high0, high1;
        ++low;
        --high;
        while(low < high){
            Console.WriteLine($"{mx} {mn} {nums[low]} {nums[high]}");
            low0 = nums[low] - k;
            low1 = nums[low] + k;
            high0 = nums[high] - k;
            high1 = nums[high] + k;
            
            // 交叉
            int x1 = high1, n1 = low0;
            if(x1 <= mx && n1 >= mn){
                // 内部更是如此
                return mx - mn;
            }

            int x2 = Math.Max(high0, low1);
            int n2 = Math.Min(high0, low1);
            if(x2 <= mx && n2 >= mn){
                ++low;
                --high;
                continue;
            }

            // 同侧
            if(mn <= low0 && high0 <= mx || mn <= low1 && high1 <= mx){
                return mx - mn;
            }

            // int nmx1 = Math.Max(mx, x1);
            // int nmn1 = Math.Min(mn, n1);

            int nmx10 = Math.Max(mx, x2);
            int nmn10 = Math.Min(mn, n2);

            int nmx00 = Math.Max(mx, high0);
            int nmn00 = Math.Min(mn, low0);

            int nmx11 = Math.Max(mx, high1);
            int nmn11 = Math.Min(mn, low1);

            int d10 = nmx10 - nmn10;
            int d00 = nmx00 - nmn00;
            int d11 = nmx11 - nmn11;

            int dmin = Math.Min(d10, Math.Min(d00, d11));
            if(dmin == d10){
                mx = nmx10;
                mn = nmn10;
            }else if(dmin == d00){
                mx = nmx00;
                mn = nmn00;
            }else{
                mx = nmx11;
                mn = nmn11;
            }

            ++low;
            --high;
        }
        Console.WriteLine($"{mx} {mn} {nums[low]} {nums[high]}");
        // d > k 始终成立
        if(low == high){
            int nmx = nums[low] + k;
            int nmn = nums[low] - k;
            Console.WriteLine($"low == high");
            Console.WriteLine($"{mx} {mn} {nmx} {nmn}");
            if(nmx > mx && nmn < mn){
                return Math.Min(maxret, Math.Min(nmx - mn, mx - nmn));
            }
        }
        return Math.Min(mx - mn, maxret);
    }

    public int SmallestRangeII8(int[] nums, int k) {
        int size = nums.Length;
        if(size < 2){
            return 0;
        }
        // 排序去重
        Array.Sort(nums);
        int end = 0;
        for(int i = 1; i < size; ++i){
            if(nums[i] != nums[end]){
                nums[++end] = nums[i];
            }
        }
        int low = 0, high = end;
        int d = nums[high] - nums[low]; // 最大的 d
        int maxret = d;
        if(d <= k){ // 注意等号
            return maxret;
        }
        // int ret = Math.Abs(d-2*k);
        int mx = Math.Max(nums[low] + k, nums[high] - k);
        int mn = Math.Min(nums[low] + k, nums[high] - k);
        ++low;
        --high;
        while(low < high){
            d = nums[high] - nums[low]; // 变小的 d
            if(d < k){  // d小到某个程度，中部要同侧了，直接返回
                int nmx = nums[high] + k;
                int nmn = nums[low] - k;
                return Math.Min(maxret, Math.Max(mx - mn, Math.Min(nmx - mn, mx - nmn)));
            }
            if(nums[high] + k <= mx && nums[low] - k >= mn){
                // 内部更是如此
                return mx - mn;
            }
            mx = Math.Max(mx, nums[low] + k);
            mn = Math.Min(mn, nums[high] - k);
            ++low;
            --high;
        }
        // d > k 始终成立
        if(low == high){
            int nmx = nums[low] + k;
            int nmn = nums[low] - k;
            // Console.WriteLine($"low == high");
            // Console.WriteLine($"{mx} {mn} {nmx} {nmn}");
            if(nmx > mx && nmn < mn){
                return Math.Min(maxret, Math.Min(nmx - mn, mx - nmn));
            }
        }
        return Math.Min(mx - mn, maxret);
    }

    public int SmallestRangeII9(int[] nums, int k) {
        int size = nums.Length;
        if(size < 2){
            return 0;
        }
        // 排序去重
        Array.Sort(nums);
        int end = 0;
        for(int i = 1; i < size; ++i){
            if(nums[i] != nums[end]){
                nums[++end] = nums[i];
            }
        }
        int low = 0, high = end;
        int d = nums[high] - nums[low]; // 最大的 d
        int maxret = d;
        if(d < k){ // 注意等号
            return maxret;
        }
        int ret = Math.Abs(d-2*k);
        ++low;
        --high;
        while(low < high){
            d = nums[high] - nums[low]; // 变小的 d
            if(d < k){
                // return Math.Max(ret, d);    // d小到某个程度，中部不自由了，直接返回
                // return Math.Min(maxret, 2 * k + Math.Min(nums[low-1] - nums[low], nums[high] - nums[high+1]));
                int mx = Math.Max(nums[low-1] + k, nums[high+1] - k);
                int mn = Math.Min(nums[low-1] + k, nums[high+1] - k);
                int nmx = nums[high] + k;
                int nmn = nums[low] - k;
                Console.WriteLine($"while");
                Console.WriteLine($"{mx} {mn} {nmx} {nmn}");
                return Math.Min(maxret, Math.Max(ret, Math.Min(nmx - mn, mx - nmn)));
            }
            ret = Math.Max(ret, Math.Abs(d-2*k));
            ++low;
            --high;
        }
        // d > k 始终成立
        if(low == high){
            int mx = Math.Max(nums[low-1] + k, nums[high+1] - k);
            int mn = Math.Min(nums[low-1] + k, nums[high+1] - k);
            int nmx = nums[low] + k;
            int nmn = nums[low] - k;
            Console.WriteLine($"low == high");
            Console.WriteLine($"{mx} {mn} {nmx} {nmn}");
            if(nmx > mx && nmn < mn){
                ret = Math.Max(ret, Math.Min(nmx - mn, mx - nmn));
            }

        }
        return Math.Min(ret, maxret);
    }
}
// @lc code=end
/*
[1]\n0\n
[0,10]\n2\n
[1,3,6]\n3\n
[1,3,6]\n5\n
[1,3,6]\n6\n
[1,6]\n3\n
[1,6]\n6\n
[2,7,2]\n1\n
[1,4,6,4]\n3\n
[3,4,7,0]\n5\n
[4,8,2,7,2]\n5\n
[4,3,10,2,0]\n3\n
[4,5,3,2,5]\n1\n
[10,3,1,2,4,6]\n2\n
[1583,9315,1561,7631,9157,843,2997,1293,2771,3155]\n1564\n
[3021,654,5072,9812,4636,3970,2381,1979,9794,4032]\n4121\n
[8038,9111,5458,8483,5052,9161,8368,2094,8366,9164,53,7222,9284,5059,4375,2667,2243,5329,3111,5678,5958,815,6841,1377,2752,8569,1483,9191,4675,6230,1169,9833,5366,502,1591,5113,2706,8515,3710,7272,1596,5114,3620,2911,8378,8012,4586,9610,8361,1646,2025,1323,5176,1832,7321,1900,1926,5518,8801,679,3368,2086,7486,575,9221,2993,421,1202,1845,9767,4533,1505,820,967,2811,5603,574,6920,5493,9490,9303,4648,281,2947,4117,2848,7395,930,1023,1439,8045,5161,2315,5705,7596,5854,1835,6591,2553,8628]\n
4643
*/
