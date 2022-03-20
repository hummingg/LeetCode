/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
private:
    vector<int> v;
    int maxOr = 0;
    int orValue = 0;
    int count = 0;
public:
    // 52 24;
    int countMaxOrSubsets(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            maxOr = maxOr | nums[i];
        }
        recur(nums, 0);

        return count;
    }

    void recur(vector<int>& nums, int begin){
        if(begin == nums.size()){
            return;
        }

        // 子集不含begin的递归
        recur(nums, begin+1);

        // 子集含begin的递归
        v.push_back(nums[begin]);
        int oldOrValue = orValue;
        orValue = orValue | nums[begin];
        if(orValue == maxOr){
            count++;
        }
        recur(nums, begin+1);
        orValue = oldOrValue;
        v.pop_back();   // 回溯
    }
};
// @lc code=end

