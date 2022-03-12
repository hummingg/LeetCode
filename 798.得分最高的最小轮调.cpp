/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    // Wrong Answer
    // 0 <= nums[i] < nums.length
    int bestRotation9(vector<int>& nums) {
        int size = nums.size();
        int flagSize = 2*size-1;
        // cout << size << " " << flagSize << endl;
        int maxScore = 0, maxK = 0;
        int flags[flagSize];    // 0 ~ 2n-2 对应 1-n ~ n-1
        for(int i = 0; i<flagSize; i++){
            flags[i] = 0;
        }
        // int count = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i] = i - nums[i]; // 非负可得分
            flags[nums[i]+size-1]++;
        }

        // 相差 0 的非负数，找到后可不用计算直接返回
        for(int i = 0; i < size-1; i++){
            if(nums[i]>=0 && flags[nums[i]+size-1] > 1){
                return nums[i];
            }
        }

        // 相差 0 的负数，前面的先，变成相同的非负数
        // int minTarget = size;
        int minSecondIndex1 = size;  // 各对相同负数中第二次出现该负数的所有索引的最小值
        for(int i = 0; i < size-1; i++){
            if(nums[i]<0 && flags[nums[i]+size-1] > 1){
                vector<int>::iterator it = find(nums.begin() + i + 1, nums.end(), nums[i]);
                if (it != nums.end()){
                    minSecondIndex1 = min(minSecondIndex1, (int)(it - nums.begin()));
                }
            }
        }
        // 相差 n，前面的先，变成相同的非负数
        int minSecondIndex2 = size;
        for(int i = 0; i < size-1; i++){
            if(flags[i] && flags[i+size]){
                vector<int>::iterator it = find(nums.begin(), nums.end(), i-size+1);
                if (it != nums.end()){
                    minSecondIndex2 = min(minSecondIndex2, (int)(it - nums.begin()));
                }
                it = find(nums.begin(), nums.end(), i+size-size+1);
                if (it != nums.end()){
                    minSecondIndex2 = min(minSecondIndex2, (int)(it - nums.begin()));
                }
            }
        }
        int minSecondIndex = min(minSecondIndex1, minSecondIndex2);
        if(minSecondIndex != size){
            if(minSecondIndex1 < minSecondIndex2){
                return minSecondIndex1 + 1 + nums[minSecondIndex1]-minSecondIndex1+size-1;
            }
            return minSecondIndex2 + 1;
        }
        return 0;
    }

    // 0 <= nums[i] < nums.length
    // 暴力 n^2 Time Limit Exceeded
    int bestRotation1(vector<int>& nums) {
        int maxScore = 0, maxK = 0;
        for(int k = 0; k < nums.size(); k++){   // 左移 k 个
            int score = 0;
            for(int i = 0; i < nums.size(); i++){
                // (k+n-1)%n = k-1
                // i -> (i-k+n)%n 新 = i-k or i-k+n 要得到 原i, +k 即可
                if(nums[(i+k)%nums.size()] <= i){
                    score++;
                }
            }
            if(score > maxScore){
                maxScore = score;
                maxK = k;
            }
        }
        cout << "score: " << maxScore << endl;
        return maxK;
    }
};

int main(){
    Solution s;
    vector<int> v = {6,2,8,3,5,2,4,3,7,6};
    int k = s.bestRotation1(v);
    cout << k << endl;
    for(int k = 0; k < v.size(); k++){
        // cout << "k = " << k << endl;
        // for(int i = 0; i<v.size(); i++){
        //     cout << v[(i-k)%v.size()] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < k;i++){
            cout << "\t";
        }
        // cout << endl;
        int score = 0;
        for(int i = 0; i<v.size(); i++){
            int d = i - v[(i+k)%v.size()];
            if(d>=0){
                score++;
            }
            cout << d << "\t";
        }
        for(int i = 0; i<v.size(); i++){
            cout << "*" << i - v[(i+k)%v.size()] << "\t";
        }
        cout << "!" << score;
        cout << endl;
    }
    return 0;
}
// @lc code=end

