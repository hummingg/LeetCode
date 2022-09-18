/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    // 42 15;
    int firstMissingPositive(vector<int>& nums) {
        const int N = 500001;
        // vector<bool> v(N, false);
        bool v[N] = {false};
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0 && nums[i] < N){
                v[nums[i]] = true;
            }
        }
        for(int i = 1; i < N; ++i){
            if(!v[i]){
                return i;
            }
        }
        return N;
    }
};
// @lc code=end
/*
[1]\n
[2147483647]\n
[1,2,0]\n
[3,4,-1,1]\n
[7,8,9,11,12]
*/
