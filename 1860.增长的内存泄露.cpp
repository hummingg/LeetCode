/*
 * @lc app=leetcode.cn id=1860 lang=cpp
 *
 * [1860] 增长的内存泄露
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    // 2147483647
    // 62704240\n732423786
    // 2044763854\n741884016
    // 100 35;
    vector<int> memLeak(int memory1, int memory2) {
        int deduct = 0;
        int t = 1;  // 消耗从1开始。消耗大小：1、2、3...
        // 迅速拉近距离
        if(memory1 >= memory2){
            deduct = memory1 - memory2;
        }else{
            deduct = memory2 - memory1;
        }
        // signed integer overflow
        int t_2 = ceil((sqrt(1LL+4LL*t*t-4*t+8LL*deduct)-1 ) / 2) - 1;  // - 1 避免欠费
        // signed integer overflow
        int mem = 1LL * (t + t_2) * (t_2 - t + 1) / 2;
        if(memory1 >= memory2){
            memory1 -= mem;
        }else{
            memory2 -= mem;
        }
        // 两者差不多了
        t = t_2;
        while(true){
            t++;    // 意外退出时间
            if(memory1 >= memory2){
                if(memory1 >= t){
                    memory1 -= t;
                }else{
                    return {t, memory1, memory2};
                }
            }else{
                if(memory2 >= t){
                    memory2 -= t;
                }else{
                    return {t, memory1, memory2};
                }
            }
        }
    }

    // 暴力
    vector<int> memLeak1(int memory1, int memory2) {
        int count = 0;
        while(true){
            count++;
            if(memory1 >= memory2){
                if(memory1 >= count){
                    memory1 -= count;
                }else{
                    return {count, memory1, memory2};
                }
            }else{
                if(memory2 >= count){
                    memory2 -= count;
                }else{
                    return {count, memory1, memory2};
                }
            }
        }
    }
};
// @lc code=end

