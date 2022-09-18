/*
 * @lc app=leetcode.cn id=1854 lang=cpp
 *
 * [1854] 人口最多的年份
 */

// @lc code=start
class Solution {
    // 68 84 4 7.6;
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int count[101]{};   // 1950 -> 2050
        for(int i = 0; i < logs.size(); ++i){
            for(int j = logs[i][0]-1950; j < logs[i][1]-1950; ++j){
                ++count[j];
            }
        }
        int maxNum = INT_MIN;
        int maxIdx = 0;
        for(int i = 0; i < 101; ++i){
            if(count[i] > maxNum){
                maxNum = count[i];
                maxIdx = i;
            }
        }
        return maxIdx + 1950;
    }
};
// @lc code=end

