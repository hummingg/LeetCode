/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
    // 100 65;
public:
    int heightChecker(vector<int>& heights) {
        auto expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(expected[i] != heights[i]){
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

