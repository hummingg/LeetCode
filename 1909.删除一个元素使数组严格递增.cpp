/*
 * @lc app=leetcode.cn id=1909 lang=cpp
 *
 * [1909] 删除一个元素使数组严格递增
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return true;
        }
        
        int index = 0;
        while(index < nums.size() - 1 && nums[index] < nums[index+1]){
            index++;
        }
        if(index == nums.size() - 1){
            return true;
        }

        for(int i = 0; i < size; i++){  // 假设删除第i个
            bool incr = true;
            for(int j = 0; j < size; j++){
                if(j+1 == i){
                    if(j+2 < size && nums[j] >= nums[j+2]){
                        incr = false;
                        break;
                    }
                }else if(j == i){
                    //continue;
                }
                else if(j+1 < size && nums[j] >= nums[j+1]){
                    incr = false;
                    break;
                }
            }
            if(incr){
                return true;
            }           
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v {105,924,32,968};
    cout << s.canBeIncreasing(v) << endl;
    return 0;
}
// @lc code=end

