/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    // 100 34; 100 84;
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0){
            if((n&1) == 1){
                ++count;
            }
            n >>= 1;
        }
        return count;
    }
};
// @lc code=end
/*
""00000000000000000000000000001011"\n
"00000000000000000000000010000000"\n
"11111111111111111111111111111101""
*/
