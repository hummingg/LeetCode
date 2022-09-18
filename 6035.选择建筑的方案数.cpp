/*
 * @lc app=leetcode.cn id=6035 lang=cpp
 *
 * [6035] 选择建筑的方案数
 */

// @lc code=start
class Solution {
public:
    // 35 42;
    long long numberOfWays(string s) {
        long long ret = 0;
        int size = s.size();
        vector<int> zero(size+1, 0);  // zero[i]是 s[i]不含 左边 0 的个数
        vector<int> one(size+1, 0);
        for(int i = 0; i < size; ++i){
            if(s[i] == '0'){
                zero[i+1] = zero[i] + 1;
                one[i+1] = one[i];
            }else{
                zero[i+1] = zero[i];
                one[i+1] = one[i] + 1;
            }
        }
        // cout << zero << endl;
        // cout << one << endl;
        int countZ = zero.back();
        int countO = one.back();
        for(int i = 1; i < size - 1; ++i){
            if(s[i] == '1'){
                ret += (countZ - zero[i]) * zero[i];
            }else{
                ret += (countO - one[i]) * one[i];
            }
        }
        return ret;
    }
};
// @lc code=end

