/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 *
 * https://leetcode-cn.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (44.12%)
 * Likes:    444
 * Dislikes: 0
 * Total Accepted:    50.4K
 * Total Submissions: 109.5K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,5,2,6], k = 100
 * 输出：8
 * 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 0
 * 输出：0
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 8 91; 26 78; 83 90;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2){
            return 0;
        }
        int ret = 0;
        int size = nums.size();
        int i = 0, j = 0, preMul = 1;
        while(i < size){
            // 不会出现 0
            // if(nums[i] == 0){
            //     ret += size-1-i;
            //     ++i;
            //     preMul = 1;
            //     j = i;
            //     continue;
            // }
            while(j < size && preMul < k){
                preMul *= nums[j++];
            }
            if(j == size && preMul < k){
                // cout << i << " " << nums[i] << " " << j-i << endl;
                ret += j-i;
            }else{  // preMul >= k
                // cout << i << " " << nums[i] << " " << j-i-1 << endl;
                ret += j-i-1;
            }
            preMul /= nums[i];
            ++i;
        }
        return ret;
    }
};
// @lc code=end
/*
[10,5,2,6]\n100\n
[1,2,3]\n0
*/
