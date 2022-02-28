/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 *
 * [1689] 十-二进制数的最少数目
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 
using namespace std;
// @lc code=start
class Solution {
public:
    // 脑筋急转弯!
    int minPartitions(string n) {
        int maxNum = 1;
        for(int i = 0; i < n.size(); i++){
            int num = n[i] - '0';
            if(num == 9){
                return 9;
            }else{
                maxNum = maxNum > num ? maxNum : num;
            }
        }
        return maxNum;
    }

    int minPartitions3(string n) {
        set<int> all;
        vector<int> exist;
        for(int i = 0; i < 10; i++){
            all.insert(i);
        }
        int i = 0;
        while(all.size() > 0 && i < n.length()){
            int num = n[i] - '0';
            auto it = all.find(num);
            if(it != all.end()){
                all.erase(num);
                exist.push_back(num);
            }
            i++;
        }
        sort(exist.begin(), exist.end());
        int count = exist[0];
        for(int i = 1; i < exist.size(); i++){
            count += exist[i] - exist[i-1];
        }
        return count;
    }

    // 93 81;
    int minPartitions2(string n) {
        int nums[10] = {};  // 全部初始化为0,统计出现0-9各自的出现次数
        for(int i = 0; i < n.length(); i++){
            int num = n[i] - '0';
            nums[num]++;
        }

        int minCount = INT_MAX, minIndex = 0;
        int count = 0;
        for(int round = 0; round < 9; round++){
            for(int i = 0; i < 10; i++){
                cout << nums[i] << " ";
            }
            cout << endl;
            for(int i = 1; i < 10; i++){    // i=0不用参与
                if(nums[i] > 0){
                    // minCount = nums[i];
                    minIndex = i;
                    break;
                }
            }
            if(minIndex == 0){
                break;
            }
            count += minIndex;
            for(int j = minIndex+1; j < 10; j++){
                nums[j-minIndex] = nums[j];
            }
            for(int j = 10 - minIndex; j < 10; j++){
                nums[j] = 0;
            }
            // minCount = INT_MAX;
            minIndex = 0;
        }

        return count > 0 ? count : 1;
    }

    // Time Limit Exceeded
    int minPartitions1(string n) {
        vector<int> nums;
        int minNumOld = 9, minNumNew = 9;
        for(int i = 0; i < n.length(); i++){
            int num = n[i] - '0';
            if(num != 0){
                if(minNumOld > num){
                    minNumOld = num;
                }
                nums.push_back(num);
            }
        }

        int count = 0;
        while(nums.size() > 0){
            for(auto it = nums.begin(); it != nums.end();){
                if(*it == minNumOld){
                    it = nums.erase(it);
                }else{
                    *it = *it - minNumOld;
                    if(*it < minNumNew){
                        minNumNew = *it;
                    }
                    it++;
                }
            }
            count += minNumOld;
            minNumOld = minNumNew;
            minNumNew = 9;
        }
        return count;
    }
};

// int main(){
//     Solution s;
//     //"32"
//     // "82734"
//     // "27346209830709182346"
//     string str = "27346209830709182346";
//     cout << s.minPartitions(str) << endl;
//     return 0;
// }
// @lc code=end

