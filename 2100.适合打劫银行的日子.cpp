/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 99 84;79 86；
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> v;
        int size = security.size();
        if(time == 0){
            for(int i = 0; i < size; i++){
                v.push_back(i);
            }
            return v;
        }
        int posbSize = size - time * 2;
        if(posbSize < 1){
            return {};
        }

        vector<bool> up, down;
        up.assign(posbSize, false);
        down.assign(posbSize, false);
        // downCount：前面（含i在内）连续 downCount 个数是非递增的
        // upCount：后面（含i在内）连续 upCount 个数是非递减的
        int upCount = 1, downCount = 1; 
        for(int i = 1; i < size - time; i++){
            if(security[i-1] >= security[i]){
                downCount++;
            }else{
                downCount = 1;
            }
            if(downCount > time && i < size-time){
                down[i-time] = true;  // 因为 downCount>time 条件，i-time 不可能越界
            }
        }
        for(int i = size-2; i > time-1; i--){
            if(security[i] <= security[i+1]){
                upCount++;
            }else{
                upCount = 1;
            }
            if(upCount > time && i >= time){
                up[i-time] = true;  // 因为 upCount>time 条件，i-time 不可能越界
            }
        }

        for(int i = time; i < size - time; i++){
            if(down[i-time] && up[i-time]){
                v.push_back(i);
            }
        }
        return v;
    }
};
// @lc code=end

