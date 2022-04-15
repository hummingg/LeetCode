/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution {
public:
    // 100 47;
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> m;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            ++m[nums[i]];
        }
        for(auto it = m.begin(); it!=m.end(); ++it){
            if(it->second > 1){
                count += it->second * (it->second-1) / 2;
            }
        }
        return count;
    }
    // 19 24;
    int numIdenticalPairs1(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

