/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
    // 44 51;
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int curhigh = 0;
        for(int i = 0; i < gain.size(); ++i){
            curhigh = curhigh + gain[i];
            highest = max(highest, curhigh);
        }
        return highest;
    }
};
// @lc code=end

