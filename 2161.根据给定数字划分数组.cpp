/*
 * @lc app=leetcode.cn id=2161 lang=cpp
 *
 * [2161] 根据给定数字划分数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // Time Limit Exceeded * 2
    // n^2 1：仿冒泡排序
    vector<int> pivotArray(vector<int>& nums, int pivot){
        int size = nums.size();
        for(int round = 0; round < size; round++){
            bool swaped = false;
            for(int i = 0; i < size - 1 - round; i++){
                if(nums[i] > pivot && nums[i+1] <= pivot 
                    || nums[i] == pivot && nums[i+1] < pivot){
                    int tmp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = tmp;
                    swaped = true;
                }
            }
            if(!swaped){
                break;
            }
        }
        return nums;
    }
    
    // n n
    vector<int> pivotArray2(vector<int>& nums, int pivot){
        vector<int> lows, highs;
        int count_pivot = 0;
        for(auto it = nums.begin(); it != nums.end();it++){
            if(*it == pivot){
                count_pivot++;
            }else if(*it < pivot){
                lows.push_back(*it);
            }else{
                highs.push_back(*it);
            }
        }
        vector<int> pivots(count_pivot, pivot);
        nums.clear();
        nums.assign(lows.begin(), lows.end());
        nums.insert(nums.end(), pivots.begin(), pivots.end());
        nums.insert(nums.end(), highs.begin(), highs.end());
        return nums;
    }

    // 错误解法
    vector<int> pivotArray999(vector<int>& nums, int pivot){
        int count_pivot = 0;
        for(auto it = nums.begin(); it != nums.end();){
            if(*it == pivot){
                count_pivot++;
                it = nums.erase(it);
            }else{
                it++;
            }
        }
        for(auto it = nums.begin(); it != nums.end(); it++){
            cout << *it  << " ";
        }
        cout << endl;
        cout << "pivot数量为：" << count_pivot << endl;

        int low = 0, high = nums.size() - 1;
        int tmp;
        while(low <= high){
            // 从前往后：找到第一个比pivot大的，从此往后找到第一个比pivot小的，然后交换
            while(low <= high && nums[low] < pivot) low++; // 找到第一个比pivot大的
            int i = low;
            while(i <= high && nums[i] > pivot) i++;    // 从此往后找到第一个比pivot小的
            if(i <= high){
                tmp = nums[low];
                nums[low] = nums[i];
                nums[i]= tmp;
                low = i;
            }else{
                break;
            }
            // 从后往前：找到第一个比pivot小的，从此往前找到第一个比pivot大的，然后交换
            while(low <= high && nums[high] > pivot) high--; // 找到第一个比pivot小的
            int j = high;
            while(j >= low && nums[j] < pivot) j--; // 从此往前找到第一个比pivot大的
            if(j >= low){
                tmp = nums[high];
                nums[high] = nums[j];
                nums[j]= tmp;
                high = j;
            }else{
                break;
            }
            for(auto it = nums.begin(); it != nums.end(); it++){
                cout << *it  << " ";
            }
            cout << endl;
            cout << "low: " << low << " high: " << high << endl;
        }
        if(count_pivot > 0){
            for(auto it = nums.begin(); it != nums.end(); ){
                if(*it > pivot){
                    for(int i = 0; i < count_pivot; i++){
                        // insert会将指定对象插入指定迭代器之前的位置，并返回这个位置的迭代器
                        it = nums.insert(it, pivot);
                    }
                    break;
                }else{
                    it++;
                }
            }
        }
        return nums;
    }

    // Time Limit Exceeded * 2
    vector<int> pivotArray1(vector<int>& nums, int pivot){
        for(int i = 1; i < nums.size(); i++){
            int j = i - 1;  // j开始往前已局部有序
            int num = nums[i];
            if(num < pivot){
                // 往前找第一个 < pivot 的位置，然后插在其后
                while(j > -1 && nums[j] >= pivot){
                    nums[j+1] = nums[j];
                    j--;
                }
                nums[j+1] = num;
            }else if(num == pivot){
                // 往前找第一个 <= pivot 的位置，然后插在其后
                while(j > -1 && nums[j] > pivot){
                    nums[j+1] = nums[j];
                    j--;
                }
                nums[j+1] = num;
            }
        }
        return nums;
    }
};
// int main(){
//     Solution s;
//     // nums = [9,12,5,10,14,3,10], pivot = 10
//     // nums = [-3,4,3,2], pivot = 2
//     // [19,15,12,-14,8,-7,-11] -7
//     vector<int> arr = {-3,4,3,2};
//     vector<int> v = s.pivotArray(arr, 2);
//     for(auto it = v.begin(); it != v.end(); it++){
//         cout << *it  << " ";
//     }
//     cout << endl;
//     return 0;
// }
// @lc code=end

