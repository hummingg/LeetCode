/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    // 进阶？
    // 93 16;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i = 0; i < nums2.size(); ++i){
            m.insert({nums2[i], i});
        }
        vector<int> ret(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); ++i){
            int j = m[nums1[i]] + 1;
            for(; j < nums2.size(); ++j){
                if(nums2[j] > nums1[i]){
                    ret[i] = nums2[j];
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

