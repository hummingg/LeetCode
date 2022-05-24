/*
 * @lc app=leetcode.cn id=2089 lang=cpp
 *
 * [2089] 找出数组排序后的目标下标
 */

// @lc code=start
class Solution {
public:
    // 快速排序？pivot = target
    // 35 41;
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == target){
                v.push_back(i);
            }
        }
        return v;
    }
};
// @lc code=end
/*
[1,2,5,2,3]\n2
[1,2,5,2,3]\n3
[1,2,5,2,3]\n5
[1,2,5,2,3]\n4
*/