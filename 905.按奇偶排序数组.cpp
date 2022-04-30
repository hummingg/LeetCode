/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (69.98%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 95.3K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。
 * 
 * 返回满足此条件的 任一数组 作为答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,2,4]
 * 输出：[2,4,3,1]
 * 解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //  73 87; 96 74; 73 40;
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            while(low < high && (nums[low] & 1) == 0)   low++;  // 从前往后找第一个奇数
            while(low < high && nums[high] & 1)  high--; // 从后往前找第一个偶数
            if(low < high) {
                swap(nums[low], nums[high]);
            }
            ++low, --high;
        }
        return nums;
    }

    // 36 64; 73 85; 
    vector<int> sortArrayByParity1(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size - 1;
        while(low < high){
            while(low < high && nums[low] % 2 == 0)   low++;  // 从前往后找第一个奇数
            while(low < high && nums[high] % 2 == 1)  high--; // 从后往前找第一个偶数
            if(low < high){ // 交换
                int tmp = nums[low];
                nums[low] = nums[high]; 
                nums[high] = tmp;
            }
            ++low, --high;
        }
        return nums;
    }
};
// @lc code=end

