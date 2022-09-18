/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        // int a = 0, b = 0;
        // int c = a ^ b;
        int c = 0;  // 不默认为0
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            c ^= nums[i];
        }
        // (a^b)^a=b, (a^b)^b=a; (a^b)^d=?
        // bitset<32> 常数空间
        int xorValue = 0;
        for(int i = 0; i < size; ++i){
            xorValue ^= nums[i];
            if(xorValue == c){  // !BUG!
                // a = nums[i];
                // b = c^nums[i];
                // return {a, b};
                // return {nums[i], c^nums[i]};
            }
        }
        for(int i = size-1; i >= 0; --i){

        }
        return {};
    }
};
// @lc code=end
/*
10 01 00 11 10 01
10 01 00 10 01 11
00 11 10 01 00 11
*/
