/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    // TLE
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return {};
        }
        sort(nums.begin(), nums.end());
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());    // 错误
        set<vector<int>> ret;
        for(int i = 0; i < size - 2; ++i){
            int target = -nums[i];
            for(int j = i+1; j < size -1 ; ++j){
                int J = nums[j];
                if(J > target && J >= 0){ // J + (J+) > target
                    break;
                }
                for(int k = j+1; k < size; ++k){
                    int cur = J + nums[k];
                    if(cur < target){
                        continue;
                    }else if(cur == target){
                        ret.insert({nums[i], J, nums[k]});
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>> vvi;
        vvi.assign(ret.begin(), ret.end());
        return vvi;
    }

    // 5 5;
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return {};
        }
        sort(nums.begin(), nums.end());
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());    // 错误
        set<vector<int>> ret;
        for(int i = 0; i < size; ++i){
            int j = i + 1, k = size-1;
            int target = -nums[i];
            while(j < k){
                int cur = nums[j] + nums[k];
                if(cur < target){
                    ++j;
                }else if(cur == target){
                    ret.insert({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }else{
                    --k;
                }
            }
        }
        vector<vector<int>> vvi;
        vvi.assign(ret.begin(), ret.end());
        return vvi;
    }
};
// @lc code=end
/*
[3,0,-2,-1,1,2]
-2 -1 0 1 2 3
*/
