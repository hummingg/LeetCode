/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 28 83;
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            int a = 0;
            for(int j = i+1; j < arr.size(); j++){
                a ^= arr[j-1];

                // 重复计算了
                // int a = 0;  // 任何数与0异或得本身
                // int m = i;  // a的起点是i，会变，要从头算
                // while(m < j){
                //     a ^= arr[m++];  // 固定 a
                // }

                int b = 0;
                for(int k = j; k < arr.size(); k++){
                    b ^= arr[k];    // b的起点是j，不会变
                    if(a == b){
                        // cout << i << " " << j << " " << k << endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

