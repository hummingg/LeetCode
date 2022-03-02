/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size = boxes.size();
        vector<int> steps(size, 0);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                // if(j == i){
                //     continue;
                // }
                if(boxes[j] == '1'){
                    steps[i] += abs(i-j);
                }
            }
        }
        return steps;
    }
};
// @lc code=end

