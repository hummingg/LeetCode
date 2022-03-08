/*
 * @lc app=leetcode.cn id=6017 lang=cpp
 *
 * [6017] 向数组中追加 K 个整数
 */

// @lc code=start
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        nums.insert(nums.begin(), 0);   // 便于处理边界
        int count = 0;
        long long sum = 0;
        for(int i = 1; i < nums.size() && k > 0; i++){
            count = nums[i]-nums[i-1]-1;
            if(count > 0){
                if(k>=count){
                    sum += 1LL * (nums[i-1]+1 + nums[i]-1) * count / 2;
                    k -= count;
                }else{
                    sum += 1LL * (nums[i-1]+1 + nums[i-1]+k) * k / 2;
                    k = 0;
                }
            }
        }
        if(k > 0){
            sum += 1LL * (nums.back()+1 + nums.back()+k) * k / 2;
        }
        return sum;
    }
};
// @lc code=end

