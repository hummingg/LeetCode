/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
    // 7 42;
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v;
        int tmp = first;
        v.push_back(tmp);
        for(auto num : encoded){
            tmp = tmp ^ num;
            v.push_back(tmp);
        }
        return v;
    }
};
// @lc code=end

