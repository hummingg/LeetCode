/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int count = 0;
        int begin = 0;
        bool in = false;
        int i = 0;
        for(; i < flowerbed.size();i++){
            if(flowerbed[i] == 0){
                if(!in){
                    begin = i;
                }
                in = true;
                count++;
            }else{
                if(begin == 0){
                    sum += count/2;
                }else{
                    sum += (count-1)/2;
                }
                count = 0;
                in = false;
            }
        }
        
        if(i == flowerbed.size() && in){
            if(begin == 0){
                sum += (count+1)/2;
            }else{
                sum += count/2;
            }
        }

        return sum >= n;
    }
};
// int main(){
//     Solution s;
//     cout << s.canPlaceFlowers() << endl;
//     return 0;
// }
// @lc code=end

