/*
 * @lc app=leetcode.cn id=2125 lang=cpp
 *
 * [2125] 银行中的激光束数量
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        for(int i = 0; i < bank.size(); i++){
            int count = 0;
            for(int j = 0; j < bank[i].size(); j++){
                if(bank[i][j] == '1'){
                    count++;
                }
            }
            if(count != 0){
                devices.push_back(count);
            }
        }

        // 解决 runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
        if(devices.size() < 2){
            return 0;
        }

        int sum = 0;
        for(int i = 0; i < devices.size()-1; i++){
            sum += devices[i] * devices[i+1];   // 未分配元素时不可使用下标，runtime error
        }
        return sum;
    }
};
// @lc code=end

