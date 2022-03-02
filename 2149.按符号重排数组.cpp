/*
 * @lc app=leetcode.cn id=2149 lang=cpp
 *
 * [2149] 按符号重排数组
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        int size = nums.size();
        for(int pos = 0, neg = 0; pos < size && neg < size; pos++, neg++){
            while(pos < size && nums[pos] < 0){
                pos++;
            }
            while(neg < size && nums[neg] > 0){
                neg++;
            }
            if(pos == size || neg == size){
                break;
            }
            v.push_back(nums[pos]);
            v.push_back(nums[neg]);
        }
        return v;
    }
};
// @lc code=end

