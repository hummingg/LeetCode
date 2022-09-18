/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // 92 19; 92 16;
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mValueIndex;
        vector<int> indexs(2, 0);

        for (int i = 0; i < nums.size(); i++){
            int pair = target-nums[i];
            auto it = mValueIndex.find(pair);
            if(it != mValueIndex.end()){
                indexs[0] = mValueIndex[pair];
                indexs[1] = i;
                break;
            }else{
                mValueIndex.insert(make_pair(nums[i], i));
            }
        }
        
        return indexs;
    }
};
// n n
// @lc code=end
int main(){
    vector<int> v = {1,2,3};
    auto vi = Solution().twoSum(v, 4);
    cout << vi[0] << " " << vi[1]  << endl;
    return 0;
}
