/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
public:
    // 8 25;
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret(l.size(), false);
        for(int i = 0; i < l.size(); i++){
            vector<int> v;  // 局部变量不用clear好维护
            for(int j = l[i]; j <= r[i]; j++){
                v.push_back(nums[j]);
            }
            if(v.size() < 3){
                ret[i] = true;
                continue;
            }
            sort(v.begin(), v.end());
            // bool eqDiff = true;
            int diff = v[1] - v[0];
            int k = 2;
            while(k < v.size() && v[k]-v[k-1] == diff){
                k++;
            }
            if(k == v.size()){
                ret[i] = true;
            }
        }
        return ret;
    }
};
// @lc code=end
//[-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10]\n[0,1,6,4,8,7]\n[4,4,9,7,9,10]
