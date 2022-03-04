/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    // 自定义排序方法，节省内存
    static bool newLess(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
    // 12 17;
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), newLess);
        int pre = -1;
        int maxWidth = 0;
        for(auto x : points){
            if(pre != -1){
                if(x[0] != pre){
                    int newWidth = x[0] - pre;
                    maxWidth = newWidth > maxWidth ? newWidth : maxWidth;
                    pre = x[0];
                }
            }else{
                pre = x[0];
            }
        }
        return maxWidth;
    }

    // 36 6;
    int maxWidthOfVerticalArea1(vector<vector<int>>& points) {
        set<int> s;
        for(int i = 0; i < points.size();i++){
            s.insert(points[i][0]);
        }
        int pre = -1;
        int maxWidth = 0;
        for(auto x : s){
            if(pre != -1){
                int newWidth = x - pre;
                maxWidth = newWidth > maxWidth ? newWidth : maxWidth;
            }
            pre = x;
        }
        return maxWidth;
    }
};
// @lc code=end

