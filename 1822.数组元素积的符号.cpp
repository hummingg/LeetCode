/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    // 86 43; 34 42; 34 44;
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                return 0;
            }else if(nums[i] < 0){
                ++neg;
            }
        }
        if(neg % 2 == 0){
            return 1;
        }
        return -1;
    }
};
// @lc code=end
/*
[-1,-2,-3,-4,3,2,1]
[1,5,0,2,-3]
[-1,1,-1,1,-1]
*/
