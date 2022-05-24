/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
class Solution {
    // 74 41;
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        vector<int> v(size);
        v[size-1] = -1;
        int maxRight = INT_MIN;
        for(int i = size-2; i >= 0; i--){
            maxRight = max(maxRight, arr[i+1]);
            v[i] = maxRight;
        }
        return v;
    }
};
// @lc code=end

