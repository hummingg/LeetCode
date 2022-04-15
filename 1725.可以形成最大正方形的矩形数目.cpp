/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start
class Solution {
public:
    // 90 28;
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        vector<int> v(rectangles.size(), 0);
        for(int i = 0; i < rectangles.size(); i++){
            v[i] = min(rectangles[i][0], rectangles[i][1]);
            if(v[i] > maxLen){
                maxLen = v[i];
            }
        }
        int ret = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] >= maxLen){
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

