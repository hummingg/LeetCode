/*
 * @lc app=leetcode.cn id=1389 lang=cpp
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start
class Solution {
public:
// 100 12;
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // int size = 0;
        // for(int i = 0; i < index.size(); i++){
        //     if(index[i] > size){
        //         size = index[i];
        //     }
        // }
        // size++;
        vector<int> ret;
        for(int i = 0; i < index.size(); i++){
            // 下标处插入值，动态插入。0 <= index[i] <= i。index[0]=0
            // ret[index[i]] = nums[i];
            ret.insert(ret.begin() + index[i], nums[i]);
        }
        return ret;
    }
};
// @lc code=end

