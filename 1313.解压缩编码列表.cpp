/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 10;
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ret;
        int i = 0;
        while(i < nums.size()){
            ret.insert(ret.end(), nums[i], nums[i+1]);
            // for(int j = 0; j < nums[i]; j++){
            //     ret.push_back(nums[i+1]);
            // }
            i += 2;
        }
        return ret;
    }
};
// @lc code=end

