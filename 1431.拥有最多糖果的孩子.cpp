/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    // 100 35;
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] > maxCandies){
                maxCandies = candies[i];
            }
        }
        vector<bool> v(candies.size(), false);
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxCandies){
                v[i] = true;
            }
        }
        return v;
    }
};
// @lc code=end

