/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (68.31%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 32.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 * 
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */

// #include "include/leetcode.h"

// @lc code=start
class Solution {
    // 54 62 64 31.4; 91 95 56  31.2;
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        for(int i = 1; i < arr.size(); ++i){
            minDif = min(minDif, arr[i] - arr[i-1]);
        }
        vector<vector<int>> ret;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - arr[i-1] == minDif){
                ret.push_back({arr[i-1], arr[i]});
            }
        }
        return ret;
    }
};
// @lc code=end

