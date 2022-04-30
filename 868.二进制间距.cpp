/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
public:
    // 100 57;
    int binaryGap(int n) {
        int ret = 0;
        int cnt = -35;  // 默认全0，没有相邻的两个 1
        int cntOne = 0;
        do{
            if(n % 2 == 1){
                ret = max(ret, cnt);
                ++cntOne;
                cnt = 1;
            }else{
                ++cnt;
            }
            n >>= 1;
        }while(n > 0);
        return cntOne > 1 ? ret : 0;
    }
};
// @lc code=end

