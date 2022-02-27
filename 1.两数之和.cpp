/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mValueIndex;
        vector<int> indexs;

        for (int i = 0; i < nums.size(); i++){
            int pair = target-nums[i];
            auto it = mValueIndex.find(pair);
            if(it != mValueIndex.end()){
                indexs.push_back(mValueIndex[pair]);
                indexs.push_back(i);
                break;
            }else{
                mValueIndex.insert(make_pair(nums[i], i));
            }
        }
        
        return indexs;
    }
};
// n n
// @lc code=end

