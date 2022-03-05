/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 方法二：n n
    // long long subArrayRanges(vector<int>& nums) {
    //     int size = nums.size();
    //     long long sum = 0;
    //     vector<int> minNums;
    //     vector<int> maxNums;

        
    //     return sum;
    // }

    // 方法一：n^2 1
    // 90 92;
    long long subArrayRanges1(vector<int>& nums) {
        int size = nums.size();
        long long sum = 0;
        for(int i = 0; i < size; i++){
            int minNum = nums[i];
            int maxNum = nums[i];
            for(int j = i+1; j<size; j++){
                int num = nums[j];
                if(num > maxNum){
                    maxNum = num;
                }else if(num < minNum){
                    minNum = num;
                }
                sum += maxNum - minNum;
            }
        }
        return sum;
    }
};
// @lc code=end

