/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "includeLc/leetcode.h"

// @lc code=start
class Solution {
    // 100 47 0 6.4;
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vvi(numRows);
        vvi[0] = {1};
        for(int i = 1; i < numRows; ++i){
            vector<int> v;
            v.push_back(1);
            for(int j = 1; j < i; ++j){
                v.push_back(vvi[i-1][j-1] + vvi[i-1][j]);
            }
            v.push_back(1);
            vvi[i] = v;
        }
        return vvi;
    }
};
// @lc code=end

int main(){
    return 0;
}
