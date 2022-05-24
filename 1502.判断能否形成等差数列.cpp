/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
class Solution {
public:
    // 100 52; 100 52;
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int size = arr.size();
        if(size < 3){
            return true;
        }
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); ++i){
            if(d != arr[i] - arr[i-1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

