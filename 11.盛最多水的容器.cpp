/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int low = 0, high = size - 1;
        int max_Area = 0, maxHeight = 0;
        while(low < high){
            // 在局部最大长方形的 长 内部时，
            // 两个 宽 都要比这个长方形的 宽 大才有可能面积更大。
            while(height[low] <= maxHeight && low < high){
                low++;
            }
            while(height[high] <= maxHeight && high > low){
                high--;
            }
            if(low >= high){
                break;
            }

            int newHeight = min(height[low], height[high]);
            int area = newHeight * (high - low);
            if(area > max_Area){
                max_Area = area;
            }
            maxHeight = newHeight;  // 更新比较基准，以继续向内找
        }
        return max_Area;
    }

    // Time Limit Exceeded
    int maxArea1(vector<int>& height) {
        int size = height.size();
        int maxArea = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int area = min(height[i], height[j]) * (j-i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }   
};
// @lc code=end

