/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int diff = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int newTarget = target - nums[i];
            for(int j = i+1, k=nums.size()-1; j<k;){
                int sum = nums[j] + nums[k];
                int newDiff = newTarget - sum;
                if(abs(diff) > abs(newDiff)){
                    result = nums[i] + sum;
                    diff = newDiff;
                }
                if(diff == 0){
                    return result;
                }
                if(sum < newTarget){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return result;
    }
};
// int main(){
//     Solution s;
//     // [-1,2,1,-4]  1   2
//     // [0,0,0]  1   0
//     // [-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33] 0   0
//     // [4,0,5,-5,3,3,0,-4,-5]   -2  -2
//     vector<int> v = {4,0,5,-5,3,3,0,-4,-5};
//     cout << s.threeSumClosest(v, -2) << endl;
//     return 0;
// }
// @lc code=end

