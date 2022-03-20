/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 8;
    vector<int> pathInZigZagTree(int label) {
        vector<int> v;
        // 奇数层序号是对的，偶数层是逆序的。
        // 从1开始，第 i 层第一个是2^(i-1)，最后一个是2^i-1。反过来，[2^(i-1) + 2^i-1] - [2^(i-1)]
        // 2^(x-1) <= label < 2^x, x-1 <= log2(label)<x+1
        int layer = floor(log2(label))+1; // 从1开始计
        int normalLabel = 0;
        if(layer % 2 == 1){
            normalLabel = label;
        }else{
            normalLabel = (pow(2, layer-1) + pow(2, layer) -1) - label;
        }
        while(normalLabel){
            v.insert(v.begin(), normalLabel);
            if(normalLabel % 2 == 1){
                normalLabel = (normalLabel-1) / 2;
            }else{
                normalLabel = normalLabel / 2;
            }
        }
        for(int i = 0; i < v.size(); i++){
            if(i % 2 == 1){ // 偶数层，v[0]是1奇数层，v[1]是2偶数层
                v[i] = (pow(2, i+1-1) + pow(2, i+1) -1) - v[i];
            }
        }
        return v;
    }
};
// @lc code=end

