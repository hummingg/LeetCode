/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    // 100 12;
    int hammingDistance(int x, int y) {
        bitset<31> bs(x^y);
        string str = bs.to_string();
        int count = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '1'){
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

