/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
    // 94 80;
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int low = 0, high = size-1;
        while(low < high){
            char tmp = s[high];
            s[high] = s[low];
            s[low] = tmp;
            ++low;
            --high;
        }
    }
};
// @lc code=end

